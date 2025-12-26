/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT uid_t __getuid()
{
  return (uid_t)__DO_SYSCALL(getuid32);
}

__EXPORT __ATTR_WEAK_ALIAS(__getuid, getuid);
