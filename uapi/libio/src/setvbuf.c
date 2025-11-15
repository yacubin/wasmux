/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdio.h>
#include <assert.h>
#include <errno.h>

int setvbuf(FILE* file, char* buf, int mode, size_t size)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
