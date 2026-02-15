/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/bulk-memory.h>

#ifndef __wasm__

void* kernel_memory_copy(void* dst, const void* src, size_t n)
{
  char* d = (char*)dst;
  const char* s = (const char*)src;

  for (size_t i = 0; i < n; ++i) {
      d[i] = s[i];
  }

  return dst;
}

void* kernel_memory_fill(void* dst, int c, size_t count)
{
  unsigned char* p = (unsigned char*)dst;

  for (size_t i = 0; i < count; ++i) {
      p[i] = (unsigned char)c;
  }

  return dst;
}

#endif /* __wasm__ */
