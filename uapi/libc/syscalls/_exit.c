/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <unistd.h>
#include <wasmux/syscalls.h>
#include <wasmux/export.h>
#include <wasmux/assert.h>

void _exit(int status)
{
  long ret = __DO_SYSCALL(exit_group, status);
  for (;;) {
    __DO_SYSCALL(exit, status);
    WA_UNREACHABLE();
  }
}

__EXPORT __ATTR_WEAK_ALIAS(_exit, _Exit);
