/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/wait.h>
#include <wasmux/assert.h>
#include <errno.h>

pid_t wait(int* stat_loc)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
