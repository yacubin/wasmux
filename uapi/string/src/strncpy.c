/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

char* __ATTR_WEAK strncpy(char* dst, const char* src, size_t n)
{
  size_t i = 0;
  while (i < n) {
    if ((dst[i] = src[i]) == '\0')
      break;
    i++;
  }
  return dst;
}
