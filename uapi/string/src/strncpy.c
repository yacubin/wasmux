/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

char* __ATTR_WEAK strncpy(char* dst, const char* src, size_t n)
{
  for (size_t i = 0; i < n; i++) {
    char ch = dst[i] = src[i];
    if (ch == '\0') {
      if (++i < n)
        __builtin_memset(&dst[i], 0, n - i);
      break;
    }
  }
  return dst;
}
