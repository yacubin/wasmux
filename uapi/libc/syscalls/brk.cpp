/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <kernel/compiler.h>
#include <kernel/errno.h>
#include <kernel/thread_data.h>
#include <kernel/syscalls.h>

extern "C" void* __curbrk = nullptr;

__ATTR_HIDDEN
extern "C" int __brk(void* addr)
{
  __curbrk = reinterpret_cast<void*>(sys_brk(reinterpret_cast<unsigned long>(addr)));
  if (__curbrk < addr) {
    __set_local_errno(ENOMEM);
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__brk, brk) __ATTR_WEAK;
