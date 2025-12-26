/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT pid_t __gettid()
{
  return (pid_t)__DO_SYSCALL(gettid);
}

__EXPORT __ATTR_WEAK_ALIAS(__gettid, gettid);
