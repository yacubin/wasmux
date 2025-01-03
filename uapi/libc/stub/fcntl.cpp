/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "fcntl.h"

#include <kernel/assert.h>
#include <errno.h>

int fcntl(int fd, int cmd, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
