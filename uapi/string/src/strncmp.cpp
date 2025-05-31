/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <string.h>

int strncmp(const char* s1, const char* s2, size_t n)
{
  return wasmux::charactersCompare(s1, s2, n);
}
