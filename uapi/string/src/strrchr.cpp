/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <string.h>
#include <wasmux/compiler.h>

extern "C" char* __strrchr(const char* str, int ch)
{
  return reinterpret_cast<char*>(memrchr(str, ch, strlen(str) + 1));
}

extern "C" __ATTR_ALIAS(__strrchr, strrchr) __ATTR_WEAK;
