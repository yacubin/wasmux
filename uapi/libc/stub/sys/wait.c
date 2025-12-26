/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/wait.h>
#include <assert.h>
#include <errno.h>

pid_t wait(int* stat_loc)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
