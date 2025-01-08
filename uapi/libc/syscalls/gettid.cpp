/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" pid_t __gettid()
{
  return static_cast<pid_t>(sys_gettid());
}

extern "C" __ATTR_ALIAS(__gettid, gettid) __ATTR_WEAK;
