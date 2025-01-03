/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <kernel/types.h>
#include <kernel/stdarg.h>
#include <kernel/compiler.h>

namespace WAF {

typedef void (PrintCallback) (void* ptr, const char* str, unsigned len);

int printTo(PrintCallback* callback, void* ptr, const char* fmt, va_list args) __ATTR_PRINTF(3, 0);

}  // namespace WAF
