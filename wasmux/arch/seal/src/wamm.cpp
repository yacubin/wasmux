/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>
#include <wasmux/errno.h>
#include <wasmux/wasm_page.h>
#include <wasmux/wasm_symbols.h>
#include <wasmux/arch/syscall-define.h>
#include <wasmux/arch/unistd.h>

#define ARCH_HAS_OWN_WAMM

#ifdef __ARCH_WANT_SYS_BRK

SYSCALL_DEFINE1(brk, unsigned long, brk)
{
#ifdef ARCH_HAS_OWN_WAMM
  constexpr unsigned kMemoryIndex = 0;
  static unsigned long __curbrk = reinterpret_cast<unsigned long>(&__heap_base);

  if (brk < reinterpret_cast<unsigned long>(&__heap_base))
    return __curbrk;

  if (brk == __curbrk)
    return __curbrk;

  if (brk > __curbrk) {
    unsigned long sizeInBytes = __builtin_wasm_memory_size(kMemoryIndex) * WA_MEMORY_PAGE_SIZE;
    if (brk > sizeInBytes) {
      unsigned curpages = sizeInBytes / WA_MEMORY_PAGE_SIZE;
      unsigned total = (brk + (WA_MEMORY_PAGE_SIZE - 1)) / WA_MEMORY_PAGE_SIZE;
      unsigned delta = total - curpages;
      if (__builtin_wasm_memory_grow(kMemoryIndex, delta) <= 0)
        return __curbrk;
    }
  }

  __curbrk = brk;
  return brk;
#else
  WA_UNREACHABLE();
  return -ENOSYS;
#endif
}

#endif
