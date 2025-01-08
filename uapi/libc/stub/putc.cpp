/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdio.h"

#include <wasmux/assert.h>
#include <errno.h>

int putc(int ch, FILE* file)
{
  errno = ENOSYS;
  WA_UNREACHABLE();
  return -1;
}
