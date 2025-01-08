/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/uio.h>
#include <errno.h>
#include <wasmux/assert.h>

ssize_t readv(int fd, const struct iovec* iov, int count)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

ssize_t writev(int fd, const struct iovec* iov, int count)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
