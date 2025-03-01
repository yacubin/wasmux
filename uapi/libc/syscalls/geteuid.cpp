/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" uid_t __geteuid()
{
  return static_cast<uid_t>(__SYSCALL(geteuid32));
}

extern "C" __ATTR_ALIAS(__geteuid, geteuid) __ATTR_WEAK;
