/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <unistd.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __vhangup(void)
{
  auto ret = __DO_SYSCALL(vhangup);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
    return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__vhangup, vhangup) __ATTR_WEAK;
