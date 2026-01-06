/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/log.h>
#include <wasmux/arch/log.h>

int wasmux_log_vprint(const char* file, int line, const char* func, wasmux_log_level level, const char* fmt, va_list args)
{
  return arch_log_vprint(file, line, func, level, fmt, args);
}

int wasmux_log_print(const char* file, int line, const char* func, wasmux_log_level level, const char* fmt, ...)
{
  int ret;
  va_list args;

  va_start(args, fmt);
  ret = wasmux_log_vprint(file, line, func, level, fmt, args);
  va_end(args);

  return ret;
}
