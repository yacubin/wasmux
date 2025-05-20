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

SYSCALL_DEFINE1(brk, unsigned long, brk) __ATTR_WEAK
{
#ifdef ARCH_HAS_WAMM
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
  return -ENOSYS;

#endif
}

#endif /* __ARCH_WANT_SYSCALL_DEFINES */
