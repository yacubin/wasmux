/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <assert.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

char* __stpncpy(char* dst, const char* src, size_t n)
{
  assert(0);
  return NULL;
}

__EXPORT __ATTR_WEAK_ALIAS(__stpncpy, stpncpy);
