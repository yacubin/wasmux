/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/reboot.h>
#include <errno.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
extern "C" int __reboot(int type)
{
  auto ret = __DO_SYSCALL(reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, type);
  if (ret < 0) {
    __set_local_errno(-static_cast<int>(ret));
  return -1;
  }

  return 0;
}

extern "C" __ATTR_ALIAS(__reboot, reboot) __ATTR_WEAK;
