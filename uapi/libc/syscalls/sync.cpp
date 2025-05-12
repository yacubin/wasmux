/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <bits/syscalls.h>
#include <unistd.h>

__ATTR_HIDDEN
extern "C" void __sync()
{
  __DO_SYSCALL(sync);
}

extern "C" __ATTR_ALIAS(__sync, sync) __ATTR_WEAK;
