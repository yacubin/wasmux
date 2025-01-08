/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/resource.h"

#include <wasmux/assert.h>
#include <errno.h>

int getrlimit(int resource, struct rlimit* rlim)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setrlimit(int resource, const struct rlimit* rlim)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int getrusage(int who, struct rusage* usage)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int getpriority(int which, id_t who)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int setpriority(int which, id_t who, int value)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
