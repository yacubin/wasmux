/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <asm/syscalls.h>
#include <unistd.h>

__ATTR_HIDDEN
extern "C" pid_t __getpid()
{
  return static_cast<pid_t>(__DO_SYSCALL(getpid));
}

extern "C" __ATTR_ALIAS(__getpid, getpid) __ATTR_WEAK;
