/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <assert.h>
#include <errno.h>

ssize_t read(int fd, void* buf, size_t count)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
