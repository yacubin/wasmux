/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <unistd.h>

__ATTR_HIDDEN
extern "C" gid_t __getegid()
{
  return static_cast<gid_t>(__DO_SYSCALL(getegid32));
}

extern "C" __ATTR_ALIAS(__getegid, getegid) __ATTR_WEAK;
