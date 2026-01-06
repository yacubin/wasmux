/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

__EXPORT void* __curbrk;
#define BAD_ADDR ((void*)-1)

__EXPORT __ATTR_HIDDEN void* __sbrk(intptr_t increment)
{
  if (__curbrk == NULL) {
    if (brk(NULL) < 0)
      return BAD_ADDR;
  }

  if (increment == 0) {
    return __curbrk;
  }

  void* addr = __curbrk;
  if (brk(((char*)addr) + increment) < 0) {
    return BAD_ADDR;
  }

  return addr;
}

__EXPORT __ATTR_WEAK_ALIAS(__sbrk, sbrk);
