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
extern "C" pid_t __getpgrp(void)
{
  return static_cast<pid_t>(__SYSCALL(getpgrp));
}

extern "C" __ATTR_ALIAS(__getpgrp, getpgrp) __ATTR_WEAK;
