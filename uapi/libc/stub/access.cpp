/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <unistd.h>
#include <assert.h>
#include <errno.h>

int access(const char* path, int mode)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int link(const char* oldpath, const char* newpath)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int unlink(const char* path)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

ssize_t readlink(const char* path, char* buf, size_t len)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int symlink(const char* target, const char* path)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int linkat(int olddirfd, const char* oldpath, int newdirfd, const char* newpath, int flags)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int unlinkat(int dirfd, const char* path, int flags)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int dup(int fd)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int dup3(int oldfd, int newfd, int flags)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
