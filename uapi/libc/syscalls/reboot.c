/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/reboot.h>
#include <stddef.h>
#include <errno.h>
#include <wasmux/export.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN
__EXPORT int __reboot(int type)
{
  long ret = __DO_SYSCALL(reboot, LINUX_REBOOT_MAGIC1, LINUX_REBOOT_MAGIC2, type, NULL);
  if (ret < 0) {
    __set_local_errno(-((int)ret));
    return -1;
  }

  return 0;
}

__EXPORT __ATTR_WEAK_ALIAS(__reboot, reboot);
