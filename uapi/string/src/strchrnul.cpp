/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <wasmux/compiler.h>
#include <wasmux/cxx/Characters.h>

char* __strchrnul(const char* str, int ch)
{
  return const_cast<char*>(WAF::charactersFind<char,false>(str, ch));
}

extern "C" __ATTR_ALIAS(__strchrnul, strchrnul) __ATTR_WEAK;
