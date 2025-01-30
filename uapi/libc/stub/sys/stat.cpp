/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/stat.h"

#include <wasmux/assert.h>
#include <errno.h>

int fstat(int fd, struct stat* buf)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int lstat(const char* path, struct stat* buf)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int mkdir(const char* path, mode_t mode)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fchmod(int fd, mode_t mode)
{
  WA_UNREACHABLE();
  return -1;
}

int chmod(const char* path, mode_t mode)
{
  WA_UNREACHABLE();
  return -1;
}

int mkdirat(int dirfd, const char* path, mode_t mode)
{
  WA_UNREACHABLE();
  return -1;
}

int mkfifo(const char* path, mode_t mode)
{
  WA_UNREACHABLE();
  return -1;
}

mode_t umask(mode_t mask)
{
  WA_UNREACHABLE();
  return -1;
}
