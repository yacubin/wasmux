/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/sysmacros.h"

#include <kernel/assert.h>
#include <errno.h>

dev_t makedev(unsigned major, unsigned minor)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

unsigned major(dev_t dev)
{
  WA_UNREACHABLE();
  return 0;
}

unsigned minor(dev_t dev)
{
  WA_UNREACHABLE();
  return 0;
}
