/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <stdint.h>
#include <stdlib.h>

extern "C" uintptr_t __stack_chk_guard;
extern "C" void __stack_chk_fail(void) __ATTR_NORETURN;

uintptr_t __stack_chk_guard = 0;

void __stack_chk_fail(void)
{
  // STDERR: "stack smashing detected"
  abort();
}
