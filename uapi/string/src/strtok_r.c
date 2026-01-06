/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <assert.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

char* __strtok_r(char* str, const char* delim, char** saveptr)
{
  assert(0);
  return NULL;
}

__EXPORT __ATTR_WEAK_ALIAS(__strtok_r, strtok_r);
