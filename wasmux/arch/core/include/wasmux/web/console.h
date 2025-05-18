/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_CONSOLE_H
#define _WASMUX_WEB_CONSOLE_H

#include <wasmux/compiler.h>
#include <wasmux/stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum WebConsoleLevel {
  WEB_CONSOLE_DEFAULT = -1,
  WEB_CONSOLE_ERROR = 3,
  WEB_CONSOLE_WARN = 4,
  WEB_CONSOLE_INFO = 6,
  WEB_CONSOLE_DEBUG = 7,
} WebConsoleLevel;

int WebConsoleWrite(int level, const char* message, unsigned length);

int WebConsoleVPrint(const char* fmt, va_list args) __ATTR_PRINTF(1, 0);
int WebConsolePrint(const char* fmt, ...) __ATTR_PRINTF(1, 2);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_CONSOLE_H */
