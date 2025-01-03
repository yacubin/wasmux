/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/vfs.h"

#include <kernel/assert.h>
#include <errno.h>

int statfs(const char* path, struct statfs* buf)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fstatfs(int fd, struct statfs* buf)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
