/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "unistd.h"

#include <kernel/assert.h>
#include <errno.h>

off_t lseek(int fildes, off_t offset, int whence)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
