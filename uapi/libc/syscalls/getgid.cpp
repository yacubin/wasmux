/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" gid_t __getgid()
{
  return static_cast<gid_t>(__SYSCALL(getgid32));
}

extern "C" __ATTR_ALIAS(__getgid, getgid) __ATTR_WEAK;
