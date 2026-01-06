/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_BITSET_H
#define _WASMUX_BITSET_H

#include <wasmux/align.h>
#include <wasmux/types.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/bits.h>

#define BITS_PER_WORD (sizeof(uintptr_t) * BITS_PER_BYTE)

#define wasmux_bitset_word_size(nbits) WA_ALIGN(nbits, sizeof(uintptr_t))
#define wasmux_bitset_bit_mask(bit) ((uintptr_t)1 << (bit & (BITS_PER_WORD - 1)))

#define WASMUX_BITSET_DEFINE(name, nbits) \
  uintptr_t name[wasmux_bitset_word_size(nbits)]

static inline bool wasmux_bitset_get(const uintptr_t* bitset, size_t bit)
{
  return (bitset[bit / BITS_PER_WORD] & wasmux_bitset_bit_mask(bit)) ? true : false;
}

static inline bool wasmux_bitset_set(uintptr_t* bitset, size_t bit)
{
  uintptr_t* word = &bitset[bit / BITS_PER_WORD];
  uintptr_t mask = wasmux_bitset_bit_mask(bit);
  if (*word & mask)
    return true;
  *word |= mask;
  return false;
}

static inline bool wasmux_bitset_clear(uintptr_t* bitset, size_t bit)
{
  uintptr_t* word = &bitset[bit / BITS_PER_WORD];
  uintptr_t mask = wasmux_bitset_bit_mask(bit);
  if (!(*word & mask))
    return false;
  *word &= ~mask;
  return true;
}

static inline void wasmux_bitset_clear_all(uintptr_t* bitset, size_t nbits)
{
  kernel_memory_fill(bitset, 0, wasmux_bitset_word_size(nbits) / BITS_PER_BYTE);
}

static inline void wasmux_bitset_set_all(uintptr_t* bitset, size_t nbits)
{
  kernel_memory_fill(bitset, 0xff, wasmux_bitset_word_size(nbits) / BITS_PER_BYTE);
}

static inline void wasmux_bitset_invert_all(uintptr_t* bitset, size_t nbits)
{
  for (size_t i = 0; i < wasmux_bitset_word_size(nbits); i++)
    bitset[i] = ~bitset[i];
}

#endif /* _WASMUX_BITSET_H */
