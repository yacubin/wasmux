/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei/memory_alloc.h>
#include <wasmux/wasm_page.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/types.h>
#include <wasmux/assert.h>
#include <wasmux/mutex.h>
#include <wasmux/log.h>
#include <wasmux/bitset.h>

#include "memory_heap.h"

class MemoryManager {
public:
  void init();
  void release();

  void* allocPages(unsigned int order);
  void freePages(void* page, unsigned int order);

  void* malloc(size_t size);
  void free(void* ptr);

  struct Metrics {
    unsigned freePages;
    unsigned freeBlocks;
  };

  void fetchMetrics(Metrics& metrics);

  static constexpr uintptr_t pageSize = (1 << WA_MEMORY_PAGE_SHIFT);
  static constexpr uintptr_t pageMask = ~(pageSize - 1);

  static constexpr uintptr_t sblockShift = 12;
  static constexpr uintptr_t sblockSize = (1 << sblockShift) - sizeof(void*);

  static constexpr size_t sblocksInPage = 1 << (WA_MEMORY_PAGE_SHIFT - sblockShift);

private:
  static constexpr size_t bblockHeaderSize = sizeof(void*);
  struct BBlockHeader {
    uint32_t order;
  };

  static_assert(sizeof(BBlockHeader) <= bblockHeaderSize, "The block header exceeded fixed size");

  static constexpr size_t sblockSetSize = sblocksInPage * sizeof(void*);
  struct SBlockSet {
    uint8_t state[sblocksInPage];
    uint8_t freeCount;

    static constexpr uint8_t kUsedBlock = 0xff;

    void init(void* ptr)
    {
      this->freeCount = sblocksInPage;
      if (isPagePointer(ptr)) {
        kernel_memory_fill(this->state, 0, sizeof(this->state));
      }
      else {
        auto page = startOfPage<char*>(ptr);
        for (uint8_t i = 0; i < sblocksInPage; i++) {
          if ((page + sblockSize * i) < ptr) {
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

  void* allocPagesInternal(unsigned int order);
  void freePagesInternal(unsigned index, unsigned int order);
  void* allocBlockInternal(unsigned nblocks);

  template<typename T>
  static bool isPagePointer(T addr)
  {
    return (reinterpret_cast<uintptr_t>(addr) & ~pageMask) == 0;
  }

  template<typename TO, typename FROM>
  static TO startOfPage(FROM addr)
  {
    return reinterpret_cast<TO>((reinterpret_cast<uintptr_t>(addr) & pageMask));
  }

  template<typename T>
  static bool isBBlockPointer(T addr)
  {
    return isPagePointer(reinterpret_cast<uintptr_t>(addr) - sizeof(void*));
  }

  template<typename T>
  static bool isSBlockPointer(T addr)
  {
    return ((reinterpret_cast<uintptr_t>(addr) & ~pageMask) % sblockSize) == 0;
  }

  template<typename T>
  static unsigned sblockToIndex(T addr)
  {
    WA_ASSERT(isSBlockPointer(addr));
    return (reinterpret_cast<uintptr_t>(addr) & (pageSize - 1)) / sblockSize;
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
    return *reinterpret_cast<SBlockSet*>(sblockBegin<char*>(reinterpret_cast<uintptr_t>(addr)) + sblocksInPage * sblockSize);
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

  inline int findFreePageIndex(unsigned order) const;

  struct memory_heap m_heap;
  wa_mutex_t m_mutex;
  WASMUX_BITSET_DEFINE(m_bblockPages, WASMUX_CORE_MAX_PAGES);
  WASMUX_BITSET_DEFINE(m_sblockPages, WASMUX_CORE_MAX_PAGES);

  unsigned m_indexBase;
  unsigned m_indexStart;
  unsigned m_indexStop;

  unsigned m_freePages;
  unsigned m_freeBlocks;
};

void MemoryManager::init()
{
  memory_heap_init(&m_heap, WASMUX_CORE_INIT_PAGES, WASMUX_CORE_MAX_PAGES);

  WA_ASSERT(isPagePointer(memory_heap_data(&m_heap)));
  char* heapEnd =  reinterpret_cast<char*>(memory_heap_data(&m_heap)) + pageSize * memory_heap_size(&m_heap);

  if (reinterpret_cast<char*>(memory_heap_end(&m_heap)) != heapEnd) {
    LOG_WARN("End of heap does not match current memory size");
  }

  char* firstPage = startOfPage<char*>(memory_heap_base(&m_heap));

  wa_mutex_init(&m_mutex);
  wasmux_bitset_clear_all(m_bblockPages, WASMUX_CORE_MAX_PAGES);
  wasmux_bitset_clear_all(m_sblockPages, WASMUX_CORE_MAX_PAGES);

  m_indexBase = pageToIndex(memory_heap_data(&m_heap));
  m_indexStart = pageToIndex(firstPage);
  m_indexStop = pageToIndex(heapEnd);

  m_freePages = 0;
  m_freeBlocks = 0;

  unsigned firstFreeIndex;
  if (isPagePointer(memory_heap_base(&m_heap)))
    firstFreeIndex = m_indexStart;
  else {
    firstFreeIndex = m_indexStart + 1;
    auto& firstBSet = sblockSet(firstPage);
    if ((reinterpret_cast<char*>(&firstBSet) + sblockSetSize) < memory_heap_base(&m_heap))
      m_indexStart++;
    else {
      firstBSet.init(memory_heap_base(&m_heap));
      auto num = m_indexStart - m_indexBase;
      wasmux_bitset_set(m_sblockPages, num);
      m_freeBlocks += firstBSet.freeCount;
    }
  }

  for (unsigned index = firstFreeIndex; index < m_indexStop; index++) {
    auto num = index - m_indexBase;
    wasmux_bitset_set(m_bblockPages, num);
    m_freePages++;
  }
}

void MemoryManager::release()
{
  memory_heap_release(&m_heap);
}

void* MemoryManager::allocPages(unsigned int order)
{
  void* page;

  if (order) {
    wa_mutex_lock(&m_mutex);
    page = allocPagesInternal(order);
    wa_mutex_unlock(&m_mutex);
  }
  else {
    page = nullptr;
  }

  return page;
}

void MemoryManager::freePages(void* page, unsigned int order)
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
  if (index < m_indexStart || m_indexStop <= (index + order)) {
    LOG_ERROR("Trying to free memory beyond usage");
    return;
  }

  wa_mutex_lock(&m_mutex);
  freePagesInternal(index, order);
  wa_mutex_unlock(&m_mutex);
}

int MemoryManager::findFreePageIndex(unsigned order) const
{
  if (order <= m_freePages) {
    unsigned temp = 0;
    for (unsigned index = m_indexStart; index < m_indexStop; index++) {
      auto num = index - m_indexBase;
      if (!wasmux_bitset_get(m_bblockPages, num)) {
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

void* MemoryManager::allocPagesInternal(unsigned int order)
{
  WA_ASSERT(order);
  
  int index = findFreePageIndex(order);
  if (index != -1) {
    for (unsigned i = 0; i < order; i++) {
      auto num = index - m_indexBase + i;
      wasmux_bitset_clear(m_bblockPages, num);
      m_freePages--;
    }
    return pageOfIndex<void*>(index);
  }

  ssize_t res = memory_heap_grow(&m_heap, order);
  if (res > 0) {
    void* page = pageOfIndex<void*>(m_indexStop);
    m_indexStop += order;
    return page;
  }

  return nullptr;
}

void MemoryManager::freePagesInternal(unsigned index, unsigned int order)
{
  WA_ASSERT(order);
  WA_ASSERT(m_indexStart <= index && index <= m_indexStop);

  for (unsigned i = 0; i < order; i++) {
    auto num = index - m_indexBase + i;
    WA_ASSERT(!wasmux_bitset_get(m_bblockPages, num));
    wasmux_bitset_set(m_bblockPages, num);
    m_freePages++;
  }
}

void* MemoryManager::SBlockSet::allocBlock(unsigned nblocks)
{
  if (nblocks <= this->freeCount) {
    unsigned temp = 0;
    for (unsigned i = 0; i < sblocksInPage; i++) {
      if (this->state[i] != 0) {
        temp = 0;
      }
      else if (++temp == nblocks) {
        for (;;) {
          this->state[i] = nblocks;
          if (--temp == 0) {
            this->freeCount -= nblocks;
            size_t offset = sblockSize * (sblocksInPage - i);
            return reinterpret_cast<char*>(this) - offset;
          }
          i--;
        }
      }
    }
  }

  return nullptr;
}

int MemoryManager::SBlockSet::freeBlock(unsigned index)
{
  uint8_t nblocks = this->state[index];
  if (nblocks == 0) {
    LOG_ERROR("There was no memory allocation for %u sblock", index);
    return 0;
  }
  
  if (sblocksInPage <= nblocks) {
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

void* MemoryManager::allocBlockInternal(unsigned nblocks)
{
  WA_ASSERT(nblocks);

  if (nblocks < sblocksInPage) {
    if (nblocks <= m_freeBlocks) {
      for (unsigned index = m_indexStart; index < m_indexStop; index++) {
        auto num = index - m_indexBase;
        if (wasmux_bitset_get(m_sblockPages, num)) {
          auto& bset = sblockSet(pageOfIndex<void*>(index));
          void* ptr = bset.allocBlock(nblocks);
          if (ptr != nullptr) {
            m_freeBlocks -= nblocks;
            return ptr;
          }
        }
      }
    }

    void* page = allocPagesInternal(1);
    if (page == nullptr) {
      LOG_ERROR("All memory was used up");
      return nullptr;
    }

    unsigned index = pageToIndex(page);
    auto num = index - m_indexBase;
    wasmux_bitset_set(m_sblockPages, num);
    auto& bset = sblockSet(page);
    bset.init(page);
    void* ptr = bset.allocBlock(nblocks);
    m_freeBlocks += bset.freeCount;
    return ptr;
  }
  else {
    size_t size = WA_ALIGN(sizeof(void*) + nblocks * sblockSize, pageSize);
    unsigned order = size >> WA_MEMORY_PAGE_SHIFT;

    void* page = allocPagesInternal(order);
    if (page == nullptr) {
      LOG_ERROR("All memory was used up");
      return nullptr;
    }

    unsigned index = pageToIndex(page);
    reinterpret_cast<BBlockHeader*>(page)->order = order;
    return reinterpret_cast<char*>(page) + sizeof(void*);
  }
}

void* MemoryManager::malloc(size_t size)
{
  void* ptr;

  if (!size)
    ptr = nullptr;
  else {
    unsigned nblocks = (size + (sblockSize - 1)) / sblockSize;

    wa_mutex_lock(&m_mutex);
    ptr = allocBlockInternal(nblocks);
    wa_mutex_unlock(&m_mutex);
  }

  return ptr;
}

void MemoryManager::free(void* ptr)
{
  if (ptr == nullptr) {
    LOG_WARN("Cannot free memory for null pointer");
  }
  else if (isSBlockPointer(ptr)) {
    auto index = sblockToIndex(ptr);
    auto& bset = sblockSet(ptr);
    wa_mutex_lock(&m_mutex);
    m_freeBlocks += bset.freeBlock(index);
    if (bset.freeCount == sblocksInPage) {
      auto i = pageToIndex(sblockBegin<void*>(ptr));
      auto num = i - m_indexBase;
      wasmux_bitset_clear(m_sblockPages, num);
      m_freeBlocks -= sblocksInPage;
      freePagesInternal(i, 1);
    }
    wa_mutex_unlock(&m_mutex);
  }
  else if (isBBlockPointer(ptr)) {
    void* page = startOfPage<void*>(ptr);
    unsigned order = reinterpret_cast<BBlockHeader*>(page)->order;
    unsigned index = pageToIndex(page);
    wa_mutex_lock(&m_mutex);
    freePagesInternal(index, order);
    wa_mutex_unlock(&m_mutex);
  }
  else {
    LOG_ERROR("Invalid memory block or memory corruption has occurred");
  }
}

void MemoryManager::fetchMetrics(Metrics& metrics)
{
  wa_mutex_lock(&m_mutex);
  metrics.freePages = m_freePages;
  metrics.freeBlocks = m_freeBlocks;
  wa_mutex_unlock(&m_mutex);
}

static MemoryManager s_memoryManager;

void WebMemoryAllocInit()
{
  s_memoryManager.init();
}

void WebMemoryAllocExit()
{
  s_memoryManager.release();
}

void* WebAllocPages(unsigned int order)
{
  return s_memoryManager.allocPages(order);
}

void WebFreePages(void* page, unsigned int order)
{
  s_memoryManager.freePages(page, order);
}

void* WebMalloc(size_t size)
{
  return s_memoryManager.malloc(size);
}

void* WebZeroMalloc(size_t size)
{
  void* ptr = WebMalloc(size);
  if (ptr) {
    kernel_memory_fill(ptr, 0, size);
  }
  return ptr;
}

void WebFree(void* ptr)
{
  s_memoryManager.free(ptr);
}
