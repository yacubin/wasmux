/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SPRINTF_H
#define _WASMUX_SPRINTF_H

#include <wasmux/types.h>
#include <wasmux/stdarg.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

__EXPORT int wasmux_printcb(void (*printfn) (void* ptr, const char* str, unsigned len),
                   void* ptr,
                   const char* fmt,
                   va_list args) __ATTR_PRINTF(3, 0);

__EXPORT int __kernel_sprintf(char* buf, const char* fmt, ...) __ATTR_PRINTF(2, 3);
__EXPORT int __kernel_vsprintf(char* buf, const char* fmt, va_list args) __ATTR_PRINTF(2, 0);
__EXPORT int __kernel_snprintf(char* buf, size_t size, const char* fmt, ...) __ATTR_PRINTF(3, 4);
__EXPORT int __kernel_vsnprintf(char* buf, size_t size, const char* fmt, va_list args) __ATTR_PRINTF(3, 0);

#endif /* _WASMUX_SPRINTF_H */
