/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

#include <asm/syscalls.h>
#include <sys/klog.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" int __klogctl(int type, char* buf, int len)
{
  auto ret = static_cast<int>(__DO_SYSCALL(syslog, type, buf, len));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__klogctl, klogctl) __ATTR_WEAK;
