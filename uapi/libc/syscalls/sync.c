/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT void __sync()
{
  __DO_SYSCALL(sync);
}

__EXPORT __ATTR_WEAK_ALIAS(__sync, sync);
