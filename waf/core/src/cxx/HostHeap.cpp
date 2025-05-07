/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>
#include <wasmux/cxx/HostHeap.h>
#include <wasmux/platform.h>

#if defined(WA_OS_WINDOWS)

#include <windows.h>

#include <wasmux/log.h>
#include <wasmux/wasm_page.h>

namespace WEI {

HostHeap::HostHeap(size_t initial, size_t maximum)
  : m_data(nullptr)
  , m_heapBase(nullptr)
  , m_heapEnd(nullptr)
  , m_initial(initial)
  , m_maximum(maximum)
  , m_size(0)
{
  m_data = VirtualAlloc(nullptr, (maximum + 1) * WA_MEMORY_PAGE_SIZE,
                        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (m_data) {
    m_heapBase = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(m_data) & WA_MEMORY_PAGE_MASK);
    m_heapEnd = reinterpret_cast<char*>(m_heapBase) + m_initial * WA_MEMORY_PAGE_SIZE;
    m_size = m_initial;
  }
  else {
    LOG_ERROR("Can't allocate memory (%u)", static_cast<unsigned>(GetLastError()));
  }
}

HostHeap::~HostHeap()
{
  if (m_data) {
    VirtualFree(m_data, 0, MEM_RELEASE);
  }
}

ssize_t HostHeap::grow(uint32_t delta)
{
  ssize_t result = m_size;
  if (delta) {
    ssize_t newSize = m_size + delta;
    if (newSize < m_size || m_maximum < newSize) {
      return -1;
    }
    m_heapEnd = reinterpret_cast<char*>(m_heapEnd) + delta * WA_MEMORY_PAGE_SIZE;
    m_size = newSize;
  }
  return result;
}

}  // namespace WEI

#else

namespace WEI {

HostHeap::HostHeap(size_t initial, size_t maximum)
  : m_data(nullptr)
  , m_heapBase(nullptr)
  , m_heapEnd(nullptr)
  , m_initial(initial)
  , m_maximum(maximum)
  , m_size(0)
{
}

ssize_t HostHeap::grow(uint32_t delta)
{
  return -1;
}

}  // namespace WEI

#endif
