/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

char* __ATTR_WEAK strcpy(char* dst, const char* src)
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
