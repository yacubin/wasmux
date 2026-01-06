/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <errno.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

__EXPORT void* __curbrk;

void* __curbrk = NULL;

__EXPORT __ATTR_HIDDEN
int __brk(void* addr)
{
  __curbrk = (void*)__DO_SYSCALL(brk, addr);
  if (__curbrk < addr) {
    __set_local_errno(ENOMEM);
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__brk, brk);
