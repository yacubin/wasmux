/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <assert.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

char* __strsep(char** strp, const char* delim)
{
  assert(0);
  return NULL;
}

__EXPORT __ATTR_WEAK_ALIAS(__strsep, strsep);
