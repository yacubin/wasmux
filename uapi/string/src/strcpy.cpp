/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <string.h>

char* strcpy(char* dst, const char* src)
{
  return wasmux::charactersCopy(dst, src);
}
