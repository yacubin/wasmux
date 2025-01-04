/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdio.h"

#include <kernel/assert.h>
#include <errno.h>

int fprintf(FILE* file, const char* fmt, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int vfprintf(FILE* file, const char* fmt, va_list ap)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
