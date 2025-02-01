/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <string.h>
#include <assert.h>
#include <wasmux/compiler.h>

extern "C" char* __strsep(char** strp, const char* delim)
{
  assert(0);
  return nullptr;
}

extern "C" __ATTR_ALIAS(__strsep, strsep) __ATTR_WEAK;
