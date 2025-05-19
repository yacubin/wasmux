/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/syscalls.h>

#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>

int fcntl(int fd, int cmd, ...)
{
  int ret;
  void* arg;

  va_list args;
  va_start(args, cmd);
  arg = va_arg(args, void*);
  va_end(args);

  // TODO
  switch (cmd) {
  default:
    break;
  }

  ret = static_cast<int>(__DO_SYSCALL(fcntl64, fd, cmd, arg));
  if (ret < 0) {
    __set_local_errno(-ret);
    return -1;
  }

  return ret;
}
