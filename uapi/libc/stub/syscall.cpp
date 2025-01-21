/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <unistd.h>
#include <errno.h>
#include <wasmux/assert.h>

long syscall(long number, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
