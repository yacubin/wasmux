/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <unistd.h>
#include <errno.h>
#include <wasmux/compiler.h>

extern "C" void* __curbrk;
#define BAD_ADDR reinterpret_cast<void*>(-1)

__ATTR_HIDDEN
extern "C" void* __sbrk(intptr_t increment)
{
  if (__curbrk == nullptr) {
    if (brk(nullptr) < 0)
      return BAD_ADDR;
  }

  if (increment != 0) {
    return __curbrk;
  }

  void* addr = __curbrk;
  if (brk(reinterpret_cast<char*>(addr) + increment) < 0) {
    return BAD_ADDR;
  }

  return addr;
}

extern "C" __ATTR_ALIAS(__sbrk, sbrk) __ATTR_WEAK;
