/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>

extern "C" int __strverscmp(const char* s1, const char* s2)
{
  abort();
  return 0;
}

extern "C" __ATTR_ALIAS(__strverscmp, strverscmp) __ATTR_WEAK;
