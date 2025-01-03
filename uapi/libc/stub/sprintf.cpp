/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "stdio.h"

#include <kernel/assert.h>
#include <kernel/errno.h>

int sprintf(char* str, const char* format, ...)
{
  int ret;
  va_list args;

  va_start(args, format);
  ret = vsprintf(str, format, args);
  va_end(args);

  return ret;
}

int vsprintf(char* str, const char* format, va_list ap)
{
  WA_UNREACHABLE();
  return -1;
}

int snprintf(char* str, size_t len, const char* format, ...)
{
  int ret;
  va_list args;

  va_start(args, format);
  ret = vsnprintf(str, len, format, args);
  va_end(args);

  return ret;
}

int vsnprintf(char* buf, size_t len, const char* format, va_list ap)
{
  WA_UNREACHABLE();
  return -1;
}
