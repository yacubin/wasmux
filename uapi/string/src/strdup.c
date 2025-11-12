/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>

char* __strdup(const char* str)
{
  size_t lenz = strlen(str) + 1;

  void* ptr = malloc(lenz);
  if (ptr) {
    memcpy(ptr, str, lenz);
  }

  return (char*)ptr;
}

__ATTR_WEAK_ALIAS(__strdup, strdup);
