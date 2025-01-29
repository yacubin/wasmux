/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>
#include <wasmux/cxx/Characters.h>

extern "C" void* __memrchr(const void* mem, int ch, size_t n)
{
  auto p = reinterpret_cast<const unsigned char*>(mem) + n;
  while (n != 0) {
    if (*--p == ch)
      return const_cast<unsigned char*>(p);
    n--;
  }

  return nullptr;
}

extern "C" __ATTR_ALIAS(__memrchr, memrchr) __ATTR_WEAK;
