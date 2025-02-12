/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <assert.h>
#include <wasmux/compiler.h>

extern "C" char* __strtok_r(char* str, const char* delim, char** saveptr)
{
  assert(0);
  return nullptr;
}

extern "C" __ATTR_ALIAS(__strtok_r, strtok_r) __ATTR_WEAK;
