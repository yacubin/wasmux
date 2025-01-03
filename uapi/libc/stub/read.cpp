/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "unistd.h"

#include <kernel/assert.h>
#include <errno.h>

ssize_t read(int fd, void* buf, size_t count)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
