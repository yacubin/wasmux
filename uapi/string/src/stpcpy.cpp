/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <string.h>
#include <assert.h>
#include <wasmux/compiler.h>

extern "C" char* __stpcpy(char* dst, const char* src)
{
  assert(0);
  return nullptr;
}

extern "C" __ATTR_ALIAS(__stpcpy, stpcpy) __ATTR_WEAK;
