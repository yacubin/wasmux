/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>
#include <wasmux/cxx/Characters.h>

extern "C" char* __strdup(const char* str)
{
  size_t lenz = strlen(str) + 1;

  void* ptr = malloc(lenz);
  if (ptr) {
    memcpy(ptr, str, lenz);
  }

  return reinterpret_cast<char*>(ptr);
}

extern "C" __ATTR_ALIAS(__strdup, strdup) __ATTR_WEAK;
