/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/assert.h>
#include <wasmux/log.h>

#include "memory_manager.h"

#define WA_MEMORY_MANAGER_PAGE_MASK (~(WA_MEMORY_MANAGER_PAGE_SIZE - 1))

struct memory_manager g_memory_manager = {};

bool memory_manager_addr_valid(const memory_manager* mm, void* ptr)
{
  const void* data = memory_heap_data(&mm->heap);
  return data <= ptr && ptr < ((const char*)data + WA_MEMORY_MANAGER_PAGE_SIZE * memory_heap_size(&mm->heap));
}

static constexpr size_t bblockHeaderSize = sizeof(void*);
struct BBlockHeader {
  uint32_t order;
};

static_assert(sizeof(BBlockHeader) <= bblockHeaderSize, "The block header exceeded fixed size");

template<typename T>
static bool isPagePointer(T addr)
{
  return (reinterpret_cast<uintptr_t>(addr) & ~WA_MEMORY_MANAGER_PAGE_MASK) == 0;
}

template<typename TO, typename FROM>
static TO startOfPage(FROM addr)
{
  return reinterpret_cast<TO>((reinterpret_cast<uintptr_t>(addr) & WA_MEMORY_MANAGER_PAGE_MASK));
}

static constexpr size_t sblockSetSize = WA_MEMORY_MANAGER_SBLOCKINPAGE * sizeof(void*);

struct SBlockSet {
  uint8_t state[WA_MEMORY_MANAGER_SBLOCKINPAGE];
  uint8_t freeCount;

  static constexpr uint8_t kUsedBlock = 0xff;

  void init(void* ptr)
  {
    this->freeCount = WA_MEMORY_MANAGER_SBLOCKINPAGE;
    if (isPagePointer(ptr)) {
      kernel_memory_fill(this->state, 0, sizeof(this->state));
    }
    else {
      auto page = startOfPage<char*>(ptr);
      for (uint8_t i = 0; i < WA_MEMORY_MANAGER_SBLOCKINPAGE; i++) {
        if ((page + WA_MEMORY_MANAGER_SBLOCK_SIZE * i) < ptr) {
          this->state[i] = kUsedBlock;
          this->freeCount--;
        }
        else {
          this->state[i] = 0;
        }
      }
    }
  }

  void* allocBlock(unsigned nblocks);
  int freeBlock(unsigned index);

  bool isEmpty() const { return freeCount == 0; }
};

static_assert(sizeof(SBlockSet) <= sblockSetSize, "The BlockSet exceeded fixed size");

template<typename T>
static bool isBBlockPointer(T addr)
{
  return isPagePointer(reinterpret_cast<uintptr_t>(addr) - sizeof(void*));
}

template<typename T>
static bool isSBlockPointer(T addr)
{
  return ((reinterpret_cast<uintptr_t>(addr) & ~WA_MEMORY_MANAGER_PAGE_MASK) % WA_MEMORY_MANAGER_SBLOCK_SIZE) == 0;
}

template<typename T>
static unsigned sblockToIndex(T addr)
{
  WA_ASSERT(isSBlockPointer(addr));
  return (reinterpret_cast<uintptr_t>(addr) & (WA_MEMORY_MANAGER_PAGE_SIZE - 1)) / WA_MEMORY_MANAGER_SBLOCK_SIZE;
}

template<typename TO, typename FROM>
static TO sblockBegin(FROM addr)
{
  WA_ASSERT(isSBlockPointer(addr));
  return startOfPage<TO>(addr);
}

template<typename T>
static SBlockSet& sblockSet(T addr)
{
  return *reinterpret_cast<SBlockSet*>(sblockBegin<char*>(reinterpret_cast<uintptr_t>(addr)) + WA_MEMORY_MANAGER_SBLOCKINPAGE * WA_MEMORY_MANAGER_SBLOCK_SIZE);
}

template<typename T>
static unsigned pageToIndex(T page)
{
  return reinterpret_cast<uintptr_t>(page) >> WA_MEMORY_PAGE_SHIFT;
}

template<typename T>
static T pageOfIndex(unsigned index)
{
  return reinterpret_cast<T>(static_cast<uintptr_t>(index) << WA_MEMORY_PAGE_SHIFT);
}

void memory_manager_init(memory_manager* mm)
{
  memory_heap_init(&mm->heap, WASMUX_CORE_INIT_PAGES, WASMUX_CORE_MAX_PAGES);

  WA_ASSERT(isPagePointer(memory_heap_data(&mm->heap)));
  char* heapEnd = reinterpret_cast<char*>(memory_heap_data(&mm->heap)) + WA_MEMORY_MANAGER_PAGE_SIZE * memory_heap_size(&mm->heap);

  if (reinterpret_cast<char*>(memory_heap_end(&mm->heap)) != heapEnd) {
    LOG_WARN("End of heap does not match current memory size");
  }

  char* firstPage = startOfPage<char*>(memory_heap_base(&mm->heap));

  wa_mutex_init(&mm->mutex);
  wasmux_bitset_clear_all(mm->bblock_pages, WASMUX_CORE_MAX_PAGES);
  wasmux_bitset_clear_all(mm->sblock_pages, WASMUX_CORE_MAX_PAGES);

  mm->index_base = pageToIndex(memory_heap_data(&mm->heap));
  mm->index_start = pageToIndex(firstPage);
  mm->index_stop = pageToIndex(heapEnd);

  mm->free_pages = 0;
  mm->free_blocks = 0;

  unsigned firstFreeIndex;
  if (isPagePointer(memory_heap_base(&mm->heap)))
    firstFreeIndex = mm->index_start;
  else {
    firstFreeIndex = mm->index_start + 1;
    auto& firstBSet = sblockSet(firstPage);
    if ((reinterpret_cast<char*>(&firstBSet) + sblockSetSize) < memory_heap_base(&mm->heap))
      mm->index_start++;
    else {
      firstBSet.init(memory_heap_base(&mm->heap));
      auto num = mm->index_start - mm->index_base;
      wasmux_bitset_set(mm->sblock_pages, num);
      mm->free_blocks += firstBSet.freeCount;
    }
  }

  for (unsigned index = firstFreeIndex; index < mm->index_stop; index++) {
    auto num = index - mm->index_base;
    wasmux_bitset_set(mm->bblock_pages, num);
    mm->free_pages++;
  }
}

void memory_manager_release(memory_manager* mm)
{
  memory_heap_release(&mm->heap);
}

static inline int findFreePageIndex(const memory_manager* mm, unsigned order)
{
  if (order <= mm->free_pages) {
    unsigned temp = 0;
    for (unsigned index = mm->index_start; index < mm->index_stop; index++) {
      auto num = index - mm->index_base;
      if (!wasmux_bitset_get(mm->bblock_pages, num)) {
        temp = 0;
      }
      else if (++temp == order) {
        for (;;) {
          if (--temp == 0)
            return static_cast<int>(index);
          index--;
        }
      }
    }
  }
  return -1;
}

static void* allocPagesInternal(memory_manager* mm, unsigned int order)
{
  WA_ASSERT(order);

  int index = findFreePageIndex(mm, order);
  if (index != -1) {
    for (unsigned i = 0; i < order; i++) {
      auto num = index - mm->index_base + i;
      wasmux_bitset_clear(mm->bblock_pages, num);
      mm->free_pages--;
    }
    return pageOfIndex<void*>(index);
  }

  ssize_t res = memory_heap_grow(&mm->heap, order);
  if (res > 0) {
    void* page = pageOfIndex<void*>(mm->index_stop);
    mm->index_stop += order;
    return page;
  }

  return nullptr;
}

void* memory_manager_alloc_pages(memory_manager* mm, unsigned int order)
{
  void* page;

  if (order) {
    wa_mutex_lock(&mm->mutex);
    page = allocPagesInternal(mm, order);
    wa_mutex_unlock(&mm->mutex);
  }
  else {
    page = nullptr;
  }

  return page;
}

static void freePagesInternal(memory_manager* mm, unsigned index, unsigned int order)
{
  WA_ASSERT(order);
  WA_ASSERT(mm->index_start <= index && index <= mm->index_stop);

  for (unsigned i = 0; i < order; i++) {
    auto num = index - mm->index_base + i;
    WA_ASSERT(!wasmux_bitset_get(mm->bblock_pages, num));
    wasmux_bitset_set(mm->bblock_pages, num);
    mm->free_pages++;
  }
}

void memory_manager_free_pages(memory_manager* mm, void* page, unsigned int order)
{
  if (page == nullptr) {
    LOG_WARN("Cannot free memory for null pointer");
    return;
  }

  if (order == 0) {
    LOG_WARN("Cannot free memory for zero value orders");
    return;
  }

  unsigned index = pageToIndex(page);
  if (index < mm->index_start || mm->index_stop <= (index + order)) {
    LOG_ERROR("Trying to free memory beyond usage");
    return;
  }

  wa_mutex_lock(&mm->mutex);
  freePagesInternal(mm, index, order);
  wa_mutex_unlock(&mm->mutex);
}

void* SBlockSet::allocBlock(unsigned nblocks)
{
  if (nblocks <= this->freeCount) {
    unsigned temp = 0;
    for (unsigned i = 0; i < WA_MEMORY_MANAGER_SBLOCKINPAGE; i++) {
      if (this->state[i] != 0) {
        temp = 0;
      }
      else if (++temp == nblocks) {
        for (;;) {
          this->state[i] = nblocks;
          if (--temp == 0) {
            this->freeCount -= nblocks;
            size_t offset = WA_MEMORY_MANAGER_SBLOCK_SIZE * (WA_MEMORY_MANAGER_SBLOCKINPAGE - i);
            return reinterpret_cast<char*>(this) - offset;
          }
          i--;
        }
      }
    }
  }

  return nullptr;
}

int SBlockSet::freeBlock(unsigned index)
{
  uint8_t nblocks = this->state[index];
  if (nblocks == 0) {
    LOG_ERROR("There was no memory allocation for %u sblock", index);
    return 0;
  }

  if (WA_MEMORY_MANAGER_SBLOCKINPAGE <= nblocks) {
    LOG_ERROR("Memory corruption has occurred");
    return 0;
  }

  for (unsigned i = index + 1; i < nblocks; i++) {
    if (this->state[i] != nblocks) {
      LOG_ERROR("Index %u does not correspond to the beginning of the sblock", index);
      return 0;
    }
  }

  for (unsigned i = index; i < nblocks; i++) {
    this->state[i] = 0;
  }

  this->freeCount += nblocks;
  return nblocks;
}

static void* allocBlockInternal(memory_manager* mm, unsigned nblocks)
{
  WA_ASSERT(nblocks);

  if (nblocks < WA_MEMORY_MANAGER_SBLOCKINPAGE) {
    if (nblocks <= mm->free_blocks) {
      for (unsigned index = mm->index_start; index < mm->index_stop; index++) {
        auto num = index - mm->index_base;
        if (wasmux_bitset_get(mm->sblock_pages, num)) {
          auto& bset = sblockSet(pageOfIndex<void*>(index));
          void* ptr = bset.allocBlock(nblocks);
          if (ptr != nullptr) {
            mm->free_blocks -= nblocks;
            return ptr;
          }
        }
      }
    }

    void* page = allocPagesInternal(mm, 1);
    if (page == nullptr) {
      LOG_ERROR("All memory was used up");
      return nullptr;
    }

    unsigned index = pageToIndex(page);
    auto num = index - mm->index_base;
    wasmux_bitset_set(mm->sblock_pages, num);
    auto& bset = sblockSet(page);
    bset.init(page);
    void* ptr = bset.allocBlock(nblocks);
    mm->free_blocks += bset.freeCount;
    return ptr;
  }
  else {
    size_t size = WA_ALIGN(sizeof(void*) + nblocks * WA_MEMORY_MANAGER_SBLOCK_SIZE, WA_MEMORY_MANAGER_PAGE_SIZE);
    unsigned order = size >> WA_MEMORY_PAGE_SHIFT;

    void* page = allocPagesInternal(mm, order);
    if (page == nullptr) {
      LOG_ERROR("All memory was used up");
      return nullptr;
    }

    unsigned index = pageToIndex(page);
    reinterpret_cast<BBlockHeader*>(page)->order = order;
    return reinterpret_cast<char*>(page) + sizeof(void*);
  }
}

void* memory_manager_malloc(memory_manager* mm, size_t size)
{
  void* ptr;

  if (!size)
    ptr = nullptr;
  else {
    unsigned nblocks = (size + (WA_MEMORY_MANAGER_SBLOCK_SIZE - 1)) / WA_MEMORY_MANAGER_SBLOCK_SIZE;

    wa_mutex_lock(&mm->mutex);
    ptr = allocBlockInternal(mm, nblocks);
    wa_mutex_unlock(&mm->mutex);
  }

  return ptr;
}

void memory_manager_free(memory_manager* mm, void* ptr)
{
  if (ptr == nullptr) {
    LOG_WARN("Cannot free memory for null pointer");
  }
  else if (isSBlockPointer(ptr)) {
    auto index = sblockToIndex(ptr);
    auto& bset = sblockSet(ptr);
    wa_mutex_lock(&mm->mutex);
    mm->free_blocks += bset.freeBlock(index);
    if (bset.freeCount == WA_MEMORY_MANAGER_SBLOCKINPAGE) {
      auto i = pageToIndex(sblockBegin<void*>(ptr));
      auto num = i - mm->index_base;
      wasmux_bitset_clear(mm->sblock_pages, num);
      mm->free_blocks -= WA_MEMORY_MANAGER_SBLOCKINPAGE;
      freePagesInternal(mm, i, 1);
    }
    wa_mutex_unlock(&mm->mutex);
  }
  else if (isBBlockPointer(ptr)) {
    void* page = startOfPage<void*>(ptr);
    unsigned order = reinterpret_cast<BBlockHeader*>(page)->order;
    unsigned index = pageToIndex(page);
    wa_mutex_lock(&mm->mutex);
    freePagesInternal(mm, index, order);
    wa_mutex_unlock(&mm->mutex);
  }
  else {
    LOG_ERROR("Invalid memory block or memory corruption has occurred");
  }
}

void memory_manager_get_metrics(memory_manager* mm, struct memory_manager_metrics* metrics)
{
  wa_mutex_lock(&mm->mutex);
  metrics->free_pages = mm->free_pages;
  metrics->free_blocks = mm->free_blocks;
  wa_mutex_unlock(&mm->mutex);
}
