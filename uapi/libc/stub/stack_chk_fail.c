/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdint.h>
#include <stdlib.h>
#include <wasmux/compiler.h>

uintptr_t __stack_chk_guard;
void __stack_chk_fail(void) __ATTR_NORETURN;

uintptr_t __stack_chk_guard = 0;

void __stack_chk_fail(void)
{
  // STDERR: "stack smashing detected"
  abort();
}
