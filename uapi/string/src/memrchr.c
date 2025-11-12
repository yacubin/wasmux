/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>

void* __memrchr(const void* mem, int ch, size_t n)
{
  unsigned char* p = (unsigned char*)mem + n;
  while (n != 0) {
    if (*--p == ch)
      return p;
    n--;
  }

  return NULL;
}

__ATTR_WEAK_ALIAS(__memrchr, memrchr);
