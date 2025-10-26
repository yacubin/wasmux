/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>

extern "C" void* __memrchr(const void* mem, int ch, size_t n)
{
  unsigned char* p = (unsigned char*)mem + n;
  while (n != 0) {
    if (*--p == ch)
      return p;
    n--;
  }

  return NULL;
}

extern "C" __ATTR_ALIAS(__memrchr, memrchr) __ATTR_WEAK;
