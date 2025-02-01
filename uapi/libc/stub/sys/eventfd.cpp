/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/eventfd.h>
#include <assert.h>
#include <errno.h>

int eventfd(unsigned count, int flags)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}
