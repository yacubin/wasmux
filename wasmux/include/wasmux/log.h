/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_LOG_H
#define _WASMUX_LOG_H

#include <wasmux/types.h>
#include <wasmux/stdarg.h>
#include <wasmux/compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  WX_LOG_INFO = 'I',
  WX_LOG_WARN = 'W',
  WX_LOG_ERROR = 'E',
} wasmux_log_level;

int wasmux_log_print(const char* file, int line, const char* func, wasmux_log_level level, const char* fmt, ...) __ATTR_PRINTF(5, 6);
int wasmux_log_vprint(const char* file, int line, const char* func, wasmux_log_level level, const char* fmt, va_list args) __ATTR_PRINTF(5, 0);

#ifndef LOG_TAG
#define LOG_TAG "WASMUX"
#endif

#if !defined(NDEBUG) && LOG_ENABLED
#define LOG_INFO(...) \
  wasmux_log_print(__FILE__, __LINE__, __FUNCTION__, WX_LOG_INFO, __VA_ARGS__)

#define LOG_WARN(...) \
  wasmux_log_print(__FILE__, __LINE__, __FUNCTION__, WX_LOG_WARN, __VA_ARGS__)

#define LOG_ERROR(...) \
  wasmux_log_print(__FILE__, __LINE__, __FUNCTION__, WX_LOG_ERROR, __VA_ARGS__)

#else
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)

#endif

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_LOG_H */
