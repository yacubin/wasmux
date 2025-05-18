/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/align.h>
#include <wasmux/types.h>
#include <wasmux/bulk-memory.h>

namespace WAF {

class BitVector {
public:
};

template<size_t kSize>
class BitSet {
public:
  static constexpr unsigned bitsInWord = sizeof(uintptr_t) * 8;
  static constexpr unsigned wordSize = WA_ALIGN(kSize, sizeof(uintptr_t));

  constexpr BitSet() = default;

  inline size_t size() const { return kSize; }

  bool get(size_t bit) const
  {
    return static_cast<bool>(wortAt(bit) & bitMask(bit));
  }

  bool set(size_t bit)
  {
    uintptr_t& word = wortAt(bit);
    uintptr_t mask = bitMask(bit);
    bool oldValue = static_cast<bool>(word & mask);
    word |= mask;
    return oldValue;
  }

  bool clear(size_t bit)
  {
    uintptr_t& word = wortAt(bit);
    uintptr_t mask = bitMask(bit);
    bool oldValue = static_cast<bool>(word & mask);
    word &= ~mask;
    return oldValue;
  }

  void clearAll()
  {
    kernel_memory_fill(m_bits, 0, sizeof(m_bits));
  }

  void setAll()
  {
    kernel_memory_fill(m_bits, 0xff, sizeof(m_bits));
  }

  void invert()
  {
    for (size_t i = 0; i < wordSize; i++)
      m_bits[i] = ~m_bits[i];
  }

private:
  inline uintptr_t& wortAt(size_t bit)
  {
    return m_bits[bit / bitsInWord];
  }

  inline const uintptr_t& wortAt(size_t bit) const
  {
    return m_bits[bit / bitsInWord];
  }

  static inline uintptr_t bitMask(size_t bit)
  {
    return static_cast<uintptr_t>(1) << (bit & (bitsInWord - 1));
  }

  uintptr_t m_bits[wordSize];
};

} // namespace WAF

using WAF::BitVector;
using WAF::BitSet;
