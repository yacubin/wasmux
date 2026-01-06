/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/statvfs.h>
#include <errno.h>
#include <assert.h>

int statvfs(const char* path, struct statvfs* buf)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fstatvfs(int fd, struct statvfs* buf)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
