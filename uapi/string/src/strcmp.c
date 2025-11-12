/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

int __ATTR_WEAK strcmp(const char* str1, const char* str2)
{
  unsigned char c1, c2;

  for (;;) {
    c1 = (unsigned char)*str1;
    c2 = (unsigned char)*str2;

    if (c1 != c2)
      return c1 < c2 ? -1 : 1;

    if (!c1)
      break;

    str1++;
    str2++;
  }

  return 0;
}
