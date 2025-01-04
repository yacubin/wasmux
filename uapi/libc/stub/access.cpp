/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "unistd.h"

#include <kernel/assert.h>
#include <errno.h>

int access(const char* path, int mode)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int link(const char* oldpath, const char* newpath)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int unlink(const char* path)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

ssize_t readlink(const char* path, char* buf, size_t len)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int symlink(const char* target, const char* path)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int linkat(int olddirfd, const char* oldpath, int newdirfd, const char* newpath, int flags)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int unlinkat(int dirfd, const char* path, int flags)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int dup(int fd)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int dup2(int oldfd, int newfd)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
