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
extern "C" pid_t __getppid()
{
  return static_cast<pid_t>(__DO_SYSCALL(getppid));
}

extern "C" __ATTR_ALIAS(__getppid, getppid) __ATTR_WEAK;
