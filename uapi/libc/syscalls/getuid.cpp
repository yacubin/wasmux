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
extern "C" uid_t __getuid()
{
  return static_cast<uid_t>(sys_getuid());
}

extern "C" __ATTR_ALIAS(__getuid, getuid) __ATTR_WEAK;
