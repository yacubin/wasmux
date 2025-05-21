/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/cxx/Characters.h>

#include <string.h>

int strcmp(const char* str1, const char* str2)
{
  return WAF::charactersCompare(str1, str2);
}
