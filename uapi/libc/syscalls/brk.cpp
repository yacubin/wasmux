/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>

#include <unistd.h>
#include <errno.h>

__EXPORT void* __curbrk;

void* __curbrk = nullptr;

__EXPORT __ATTR_HIDDEN
int __brk(void* addr)
{
  __curbrk = reinterpret_cast<void*>(__DO_SYSCALL(brk, addr));
  if (__curbrk < addr) {
    __set_local_errno(ENOMEM);
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__brk, brk);
