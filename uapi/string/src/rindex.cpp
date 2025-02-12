/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>

char* rindex(const char* str, int ch)
{
  return reinterpret_cast<char*>(memrchr(str, ch, strlen(str) + 1));
}
