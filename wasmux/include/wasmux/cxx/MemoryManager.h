/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/assert.h>
#include <wasmux/mutex.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/log.h>
#include <wasmux/cxx/New.h>
#include <wasmux/cxx/BitVector.h>

namespace wasmux {

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
class MemoryManager {
public:
  explicit MemoryManager(Heap& heap);

  void* allocPages(unsigned int order);
  void freePages(void* page, unsigned int order);

  void* malloc(size_t size);
  void free(void* ptr);

  struct Metrics {
    unsigned freePages;
    unsigned freeBlocks;
  };

  void fetchMetrics(Metrics& metrics);

  static constexpr uintptr_t pageSize = (1 << pageShift);
  static constexpr uintptr_t pageMask = ~(pageSize - 1);

  static constexpr uintptr_t sblockShift = 12;
  static constexpr uintptr_t sblockSize = (1 << sblockShift) - sizeof(void*);
  // static constexpr uintptr_t blockMask = ~(blockSize - 1);

  static constexpr size_t sblocksInPage = 1 << (pageShift - sblockShift);

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

    SBlockSet(void* ptr)
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
    return reinterpret_cast<uintptr_t>(page) >> pageShift;
  }

  template<typename T>
  static T pageOfIndex(unsigned index)
  {
    return reinterpret_cast<T>(static_cast<uintptr_t>(index) << pageShift);
  }

  inline int findFreePageIndex(unsigned order) const;

  Heap& m_heap;
  wa_mutex_t m_mutex;
  BitSet<maxOrder> m_bblockPages;
  BitSet<maxOrder> m_sblockPages;

  unsigned m_indexBase;
  unsigned m_indexStart;
  unsigned m_indexStop;

  unsigned m_freePages;
  unsigned m_freeBlocks;
};

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
MemoryManager<pageShift, initOrder, maxOrder, Heap>::MemoryManager(Heap& heap)
  : m_heap(heap)
{
  WA_ASSERT(isPagePointer(m_heap.data()));
  char* heapEnd =  reinterpret_cast<char*>(m_heap.data()) + pageSize * m_heap.size();

  if (reinterpret_cast<char*>(m_heap.heapEnd()) != heapEnd) {
    LOG_WARN("End of heap does not match current memory size");
  }

  char* firstPage = startOfPage<char*>(m_heap.heapBase());

  wa_mutex_init(&m_mutex);
  m_bblockPages.clearAll();
  m_sblockPages.clearAll();

  m_indexBase = pageToIndex(m_heap.data());
  m_indexStart = pageToIndex(firstPage);
  m_indexStop = pageToIndex(heapEnd);

  m_freePages = 0;
  m_freeBlocks = 0;

  unsigned firstFreeIndex;
  if (isPagePointer(m_heap.heapBase()))
    firstFreeIndex = m_indexStart;
  else {
    firstFreeIndex = m_indexStart + 1;
    auto& firstBSet = sblockSet(firstPage);
    if ((reinterpret_cast<char*>(&firstBSet) + sblockSetSize) < m_heap.heapBase())
      m_indexStart++;
    else {
      new (wasmux::CtorOnly, &firstBSet) SBlockSet(m_heap.heapBase());
      auto num = m_indexStart - m_indexBase;
      m_sblockPages.set(num);
      m_freeBlocks += firstBSet.freeCount;
    }
  }

  for (unsigned index = firstFreeIndex; index < m_indexStop; index++) {
    auto num = index - m_indexBase;
    m_bblockPages.set(num);
    m_freePages++;
  }
}

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void* MemoryManager<pageShift, initOrder, maxOrder, Heap>::allocPages(unsigned int order)
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void MemoryManager<pageShift, initOrder, maxOrder, Heap>::freePages(void* page, unsigned int order)
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
int MemoryManager<pageShift, initOrder, maxOrder, Heap>::findFreePageIndex(unsigned order) const
{
  if (order <= m_freePages) {
    unsigned temp = 0;
    for (unsigned index = m_indexStart; index < m_indexStop; index++) {
      auto num = index - m_indexBase;
      if (!m_bblockPages.get(num)) {
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void* MemoryManager<pageShift, initOrder, maxOrder, Heap>::allocPagesInternal(unsigned int order)
{
  WA_ASSERT(order);
  
  int index = findFreePageIndex(order);
  if (index != -1) {
    for (unsigned i = 0; i < order; i++) {
      auto num = index - m_indexBase + i;
      m_bblockPages.clear(num);
      m_freePages--;
    }
    return pageOfIndex<void*>(index);
  }

  ssize_t res = m_heap.grow(order);
  if (res > 0) {
    void* page = pageOfIndex<void*>(m_indexStop);
    m_indexStop += order;
    return page;
  }

  return nullptr;
}

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void MemoryManager<pageShift, initOrder, maxOrder, Heap>::freePagesInternal(unsigned index, unsigned int order)
{
  WA_ASSERT(order);
  WA_ASSERT(m_indexStart <= index && index <= m_indexStop);

  for (unsigned i = 0; i < order; i++) {
    auto num = index - m_indexBase + i;
    WA_ASSERT(!m_bblockPages.get(num));
    m_bblockPages.set(num);
    m_freePages++;
  }
}

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void* MemoryManager<pageShift, initOrder, maxOrder, Heap>::SBlockSet::allocBlock(unsigned nblocks)
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
int MemoryManager<pageShift, initOrder, maxOrder, Heap>::SBlockSet::freeBlock(unsigned index)
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void* MemoryManager<pageShift, initOrder, maxOrder, Heap>::allocBlockInternal(unsigned nblocks)
{
  WA_ASSERT(nblocks);

  if (nblocks < sblocksInPage) {
    if (nblocks <= m_freeBlocks) {
      for (unsigned index = m_indexStart; index < m_indexStop; index++) {
        auto num = index - m_indexBase;
        if (m_sblockPages.get(num)) {
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
    m_sblockPages.set(num);
    auto& bset = sblockSet(page);
    new (wasmux::CtorOnly, &bset) SBlockSet(page);
    void* ptr = bset.allocBlock(nblocks);
    m_freeBlocks += bset.freeCount;
    return ptr;
  }
  else {
    size_t size = WA_ALIGN(sizeof(void*) + nblocks * sblockSize, pageSize);
    unsigned order = size >> pageShift;

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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void* MemoryManager<pageShift, initOrder, maxOrder, Heap>::malloc(size_t size)
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void MemoryManager<pageShift, initOrder, maxOrder, Heap>::free(void* ptr)
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
      m_sblockPages.clear(num);
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

template<size_t pageShift, size_t initOrder, size_t maxOrder, typename Heap>
void MemoryManager<pageShift, initOrder, maxOrder, Heap>::fetchMetrics(Metrics& metrics)
{
  wa_mutex_lock(&m_mutex);
  metrics.freePages = m_freePages;
  metrics.freeBlocks = m_freeBlocks;
  wa_mutex_unlock(&m_mutex);
}

} // namespace wasmux
