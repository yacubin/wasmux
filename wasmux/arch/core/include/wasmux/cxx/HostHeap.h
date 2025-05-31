/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>

namespace WEI {

class HostHeap {
public:
  HostHeap(size_t initial, size_t maximum);
  ~HostHeap();

  void* data() const { return m_data; }
  void* heapBase() const { return m_heapBase; }
  void* heapEnd() const { return m_heapEnd; }

  size_t size() const { return m_size; }
  ssize_t grow(uint32_t delta);

private:
  void* m_data;
  void* m_heapBase;
  void* m_heapEnd;
  size_t m_initial;
  size_t m_maximum;
  size_t m_size;
};

} // namespace WEI
