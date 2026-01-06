/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

int fstat(int fd, struct stat* buf)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int lstat(const char* path, struct stat* buf)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int mkdir(const char* path, mode_t mode)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fchmod(int fd, mode_t mode)
{
  assert(0);
  return -1;
}

int chmod(const char* path, mode_t mode)
{
  assert(0);
  return -1;
}

int mkdirat(int dirfd, const char* path, mode_t mode)
{
  assert(0);
  return -1;
}

int mkfifo(const char* path, mode_t mode)
{
  assert(0);
  return -1;
}

mode_t umask(mode_t mask)
{
  assert(0);
  return -1;
}

int utimensat(int dirfd, const char* path, const struct timespec times[2], int flags)
{
  assert(0);
  return -1;
}
