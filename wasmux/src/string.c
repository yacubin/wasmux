/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/string.h>

size_t wasmux_strlen(const char* s)
{
  const char* ptr = s;
  while (*ptr) {
    ptr++;
  }
  return ptr - s;
}
