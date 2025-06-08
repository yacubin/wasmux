/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <string.h>

char* strncpy(char* dst, const char* src, size_t n)
{
  return wasmux::charactersCopy(dst, src, n);
}
