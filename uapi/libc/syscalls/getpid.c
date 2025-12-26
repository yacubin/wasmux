/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT pid_t __getpid()
{
  return (pid_t)__DO_SYSCALL(getpid);
}

__EXPORT __ATTR_WEAK_ALIAS(__getpid, getpid);
