/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/string.h>
#include <wasmux/compiler.h>

__optnone size_t wasmux_strlen(const char* str)
{
  const char* ptr = str;
  while (*ptr) {
    ptr++;
  }
  return ptr - str;
}

char* wasmux_strcpy(char* dst, const char* src)
{
  char* ret = dst;
  for (;;) {
    char ch = *dst = *src;
    if (ch == '\0')
      break;
    src++;
    dst++;
  }

  return ret;
}
