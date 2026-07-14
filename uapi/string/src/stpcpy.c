/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>
#include <wasmux/string.h>

char* __stpcpy(char* dst, const char* src)
{
  size_t len = wasmux_strlen(src);
  __builtin_memcpy(dst, src, len + 1);
  return dst + len;
}

__EXPORT __ATTR_WEAK_ALIAS(__stpcpy, stpcpy);
