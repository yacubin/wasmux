/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

int putc(int ch, FILE* file)
{
  errno = ENOSYS;
  assert(0);
  return -1;
}
