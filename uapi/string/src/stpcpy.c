/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <assert.h>
#include <wasmux/compiler.h>

char* __stpcpy(char* dst, const char* src)
{
  assert(0);
  return NULL;
}

__ATTR_WEAK_ALIAS(__stpcpy, stpcpy);
