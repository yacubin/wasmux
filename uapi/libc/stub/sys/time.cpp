/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/time.h>
#include <errno.h>
#include <assert.h>
#include <wasmux/compiler.h>

int setitimer(int witch, const struct itimerval* new_value, struct itimerval* old_value)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}

int utimes(const char* filename, const struct timeval times[2])
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}
