/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <errno.h>
#include <assert.h>

int __rt_dummy(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
