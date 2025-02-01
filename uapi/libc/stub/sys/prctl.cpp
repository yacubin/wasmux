/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/prctl.h>
#include <assert.h>
#include <errno.h>

int prctl(int option, ...)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
