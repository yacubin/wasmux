/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SPRINTF_H
#define _WASMUX_SPRINTF_H

#include <wasmux/types.h>
#include <wasmux/compiler.h>
#include <wasmux/stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

int __kernel_sprintf(char* buf, const char* fmt, ...) __ATTR_PRINTF(2, 3);
int __kernel_vsprintf(char* buf, const char* fmt, va_list args) __ATTR_PRINTF(2, 0);
int __kernel_snprintf(char* buf, size_t size, const char* fmt, ...) __ATTR_PRINTF(3, 4);
int __kernel_vsnprintf(char* buf, size_t size, const char* fmt, va_list args) __ATTR_PRINTF(3, 0);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_SPRINTF_H */
