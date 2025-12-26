/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__EXPORT __ATTR_HIDDEN pid_t __getpgrp(void)
{
  return (pid_t)__DO_SYSCALL(getpgrp);
}

__EXPORT __ATTR_WEAK_ALIAS(__getpgrp, getpgrp);
