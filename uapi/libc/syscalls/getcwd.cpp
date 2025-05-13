/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <asm/syscalls.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" char* __getcwd(char* buf, size_t size)
{
  auto ret = __DO_SYSCALL(getcwd, buf, size);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return nullptr;
  }

  return buf;
}

extern "C" __ATTR_ALIAS(__getcwd, getcwd) __ATTR_WEAK;
