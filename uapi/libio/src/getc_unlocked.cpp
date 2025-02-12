/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>

int getc_unlocked(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
