/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/wait.h"

#include <kernel/assert.h>
#include <errno.h>

pid_t wait(int* stat_loc)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

pid_t waitpid(pid_t pid, int* stat_loc, int options)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
