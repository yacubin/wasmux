/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <wasmux/log.h>

#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

#include <windows.h>
#include <waf/PrintTo.h>

static void log_write(void* ptr, const char* data, unsigned size)
{
  HANDLE hConsole = reinterpret_cast<HANDLE>(ptr);
  DWORD dataWritten;
  WriteConsole(hConsole, data, size, &dataWritten, nullptr);
}

int __kernel_log_vprint(const char* file, int line, const char* func, __kernel_log_level level, const char* fmt, va_list args)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  return WAF::printTo(&log_write, hConsole, fmt, args);
}

#else

int __kernel_log_vprint(const char* file, int line, const char* func, __kernel_log_level level, const char* fmt, va_list args)
{
  return -1;
}

#endif

int __kernel_log_print(const char* file, int line, const char* func, __kernel_log_level level, const char* fmt, ...)
{
  int ret;
  va_list args;

  va_start(args, fmt);
  ret = __kernel_log_vprint(file, line, func, level, fmt, args);
  va_end(args);

  return ret;
}
