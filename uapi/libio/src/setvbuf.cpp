/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <stdio.h>
#include <wasmux/assert.h>
#include <errno.h>

int setvbuf(FILE* file, char* buf, int mode, size_t size)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
