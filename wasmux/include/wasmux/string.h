/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_STRING_H
#define _WASMUX_STRING_H

#include <wasmux/export.h>
#include <wasmux/types.h>
#include <wasmux/arch/string.h>

__EXPORT size_t wasmux_strlen(const char* s);
__EXPORT char* wasmux_strcpy(char* dst, const char* src);

#endif /* _WASMUX_STRING_H */
