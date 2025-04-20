/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <errno.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

extern "C" void* __curbrk = nullptr;

__ATTR_HIDDEN
extern "C" int __brk(void* addr)
{
  __curbrk = reinterpret_cast<void*>(__DO_SYSCALL(brk, addr));
  if (__curbrk < addr) {
    __set_local_errno(ENOMEM);
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__brk, brk) __ATTR_WEAK;
