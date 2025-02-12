/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <string.h>
#include <stdlib.h>
#include <wasmux/compiler.h>
#include <wasmux/cxx/Characters.h>

extern "C" void* __memchr(const void* mem, int ch, size_t n)
{
  return const_cast<uint8_t*>(WAF::charactersFind<uint8_t,true>(
    reinterpret_cast<const uint8_t*>(mem),
    static_cast<uint8_t>(ch), n));
}

extern "C" __ATTR_ALIAS(__memchr, memchr) __ATTR_WEAK;
