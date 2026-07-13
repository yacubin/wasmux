/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <stdlib.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

void* __memchr(const void* mem, int ch, size_t n)
{
  const unsigned char* ptr = mem;
  const unsigned char* end = ptr + n;
  while (ptr < end) {
    if (*ptr == (unsigned char)ch)
      return ptr;
    ptr++;
  }
  return NULL;
}

__EXPORT __ATTR_WEAK_ALIAS(__memchr, memchr);
