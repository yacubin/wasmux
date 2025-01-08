/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "unistd.h"

#include <wasmux/assert.h>
#include <errno.h>

int pipe(int fds[2])
{
  errno = ENOSYS;
  return -1;
}
