/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "unistd.h"

#include <kernel/assert.h>
#include <errno.h>

int pipe(int fds[2])
{
  errno = ENOSYS;
  return -1;
}
