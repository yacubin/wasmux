/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <stdio.h>
#include <wasmux/assert.h>
#include <wasmux/errno.h>

int sprintf(char* str, const char* fmt, ...)
{
  int ret;
  va_list args;

  va_start(args, fmt);
  ret = vsprintf(str, fmt, args);
  va_end(args);

  return ret;
}

int vsprintf(char* str, const char* fmt, va_list ap)
{
  WA_UNREACHABLE();
  return -1;
}

int snprintf(char* str, size_t len, const char* fmt, ...)
{
  int ret;
  va_list args;

  va_start(args, fmt);
  ret = vsnprintf(str, len, fmt, args);
  va_end(args);

  return ret;
}

int vsnprintf(char* buf, size_t len, const char* fmt, va_list ap)
{
  WA_UNREACHABLE();
  return -1;
}

int asprintf(char** str, const char* fmt, ...)
{
  int ret;
  va_list args;

  va_start(args, fmt);
  ret = vasprintf(str, fmt, args);
  va_end(args);

  return ret;
}

int vasprintf(char** str, const char* fmt, va_list ap)
{
  WA_UNREACHABLE();
  return -1;
}
