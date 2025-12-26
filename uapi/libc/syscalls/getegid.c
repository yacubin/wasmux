/*
 *
 *  Copyright (C) 2025-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT gid_t __getegid()
{
  return (gid_t)__DO_SYSCALL(getegid32);
}

__EXPORT __ATTR_WEAK_ALIAS(__getegid, getegid);
