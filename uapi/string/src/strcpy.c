/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>
#include <wasmux/string.h>

char* __ATTR_WEAK strcpy(char* dst, const char* src)
{
  return wasmux_strcpy(dst, src);
}
