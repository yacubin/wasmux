/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>

namespace WAF {

namespace {

template<typename T> struct MemoryCompareHelper {
  using Type = T;
};

template<> struct MemoryCompareHelper<void> {
  using Type = uint8_t;
};

}  // namespace

template<typename T>
int memoryCompare(const T* mem1, const T* mem2, size_t n)
{
  using Type = typename MemoryCompareHelper<T>::Type;
  while (n != 0) {
    int a = *reinterpret_cast<const Type*>(mem1);
    int b = *reinterpret_cast<const Type*>(mem2);
    int diff = a - b;
    if (diff)
      return diff;
    mem1 = reinterpret_cast<const Type*>(mem1) + 1;
    mem2 = reinterpret_cast<const Type*>(mem2) + 1;
    n--;
  }
  return 0;
}

}  // namespace WAF
