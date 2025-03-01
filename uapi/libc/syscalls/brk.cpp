/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <errno.h>
#include <wasmux/wasm_symbols.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

#ifdef __wasm__
#define __CURBRK_INIT &__heap_base
#else
#define __CURBRK_INIT nullptr
#endif

extern "C" void* __curbrk = __CURBRK_INIT;

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
