/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

int __ATTR_WEAK strncmp(const char* s1, const char* s2, size_t n)
{
  unsigned char c1, c2;

  while (n != 0) {
    c1 = (unsigned char)*s1;
    c2 = (unsigned char)*s2;

    if (c1 != c2)
      return c1 < c2 ? -1 : 1;

    if (!c1)
      break;

    s1++;
    s2++;
    n--;
  }

  return 0;
}
