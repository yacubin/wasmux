/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <string.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

char* __strchrnul(const char* str, int ch)
{
  for (;;) {
    unsigned char c = (unsigned char)*str;
    if (c == '\0'|| c == (unsigned char)ch)
      break;
    str++;
  }
  return (char*)str;
}

__EXPORT __ATTR_WEAK_ALIAS(__strchrnul, strchrnul);
