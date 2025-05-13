/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <asm/syscalls.h>
#include <fcntl.h>
#include <errno.h>

int __creat(const char* path, mode_t mode)
{
  int ret = static_cast<int>(__DO_SYSCALL(creat, path, mode));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}

__ATTR_ALIAS(__creat, creat) __ATTR_WEAK;
