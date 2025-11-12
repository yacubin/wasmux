/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/compiler.h>

char* __strrchr(const char* str, int ch)
{
  return (char*)memrchr(str, ch, strlen(str) + 1);
}

__ATTR_WEAK_ALIAS(__strrchr, strrchr);
