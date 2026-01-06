/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/statfs.h>
#include <assert.h>
#include <errno.h>

int statfs(const char* path, struct statfs* buf)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}

int fstatfs(int fd, struct statfs* buf)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}
