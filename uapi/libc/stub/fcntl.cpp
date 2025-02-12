/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <cntl.h>
#include <wasmux/assert.h>
#include <errno.h>

int fcntl(int fd, int cmd, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int openat(int dirfd, const char* path, int flags, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
