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
