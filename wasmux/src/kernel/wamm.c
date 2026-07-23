/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>
#include <wasmux/wasm_page.h>
#include <wasmux/wasm_symbols.h>
#include <wasmux/assert.h>
#include <wasmux/errno.h>

#ifdef __ARCH_WANT_SYSCALL_DEFINES

#define MEMORY_INDEX 0
SYSCALL_DEFINE1(brk, unsigned long, brk)
{
#ifdef ARCH_HAS_WAMM
  static unsigned long __curbrk = (unsigned long)&__heap_base;

  if (brk < (unsigned long)&__heap_base)
    return __curbrk;

  if (brk == __curbrk)
    return __curbrk;

  if (brk > __curbrk) {
    unsigned long sizeInBytes = __builtin_wasm_memory_size(MEMORY_INDEX) * WA_MEMORY_PAGE_SIZE;
    if (brk > sizeInBytes) {
      unsigned curpages = sizeInBytes / WA_MEMORY_PAGE_SIZE;
      unsigned total = (brk + (WA_MEMORY_PAGE_SIZE - 1)) / WA_MEMORY_PAGE_SIZE;
      unsigned delta = total - curpages;
      if (__builtin_wasm_memory_grow(MEMORY_INDEX, delta) <= 0)
        return __curbrk;
    }
  }

  __curbrk = brk;
  return brk;

#else
  return -ENOSYS;

#endif
}

#endif /* __ARCH_WANT_SYSCALL_DEFINES */
