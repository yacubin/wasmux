/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/resource.h>
#include <assert.h>
#include <errno.h>

int getrlimit(int resource, struct rlimit* rlim)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setrlimit(int resource, const struct rlimit* rlim)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int getrusage(int who, struct rusage* usage)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int getpriority(int which, id_t who)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int setpriority(int which, id_t who, int value)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
