/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT gid_t __getgid()
{
  return (gid_t)__DO_SYSCALL(getgid32);
}

__EXPORT __ATTR_WEAK_ALIAS(__getgid, getgid);
