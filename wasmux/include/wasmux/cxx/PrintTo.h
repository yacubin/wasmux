/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/stdarg.h>
#include <wasmux/compiler.h>

namespace wasmux {

typedef void (PrintCallback) (void* ptr, const char* str, unsigned len);

int printTo(PrintCallback* callback, void* ptr, const char* fmt, va_list args) __ATTR_PRINTF(3, 0);

}  // namespace wasmux
