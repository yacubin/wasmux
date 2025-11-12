/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <assert.h>
#include <wasmux/compiler.h>

int __strverscmp(const char* s1, const char* s2)
{
  assert(0);
  return 0;
}

__ATTR_WEAK_ALIAS(__strverscmp, strverscmp);
