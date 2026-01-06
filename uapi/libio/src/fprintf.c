/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdio.h>
#include <assert.h>
#include <errno.h>

int fprintf(FILE* file, const char* fmt, ...)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int vfprintf(FILE* file, const char* fmt, va_list ap)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
