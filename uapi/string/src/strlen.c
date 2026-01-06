/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/string.h>

size_t strlen(const char* str)
{
  return wasmux_strlen(str);
}
