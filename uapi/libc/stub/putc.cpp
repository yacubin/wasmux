/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdio.h"

#include <kernel/assert.h>
#include <errno.h>

int putc(int ch, FILE* file)
{
  errno = ENOSYS;
  WA_UNREACHABLE();
  return -1;
}
