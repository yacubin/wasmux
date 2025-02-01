/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _ERR_H
#define _ERR_H

#include <stdarg.h>
#include <wasmux/compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

void warn(const char* fmt, ...) __ATTR_PRINTF(1, 2);
void warnx(const char* fmt, ...) __ATTR_PRINTF(1, 2);

void err(int status, const char* fmt, ...) __ATTR_PRINTF(2, 3) __ATTR_NORETURN;
void errx(int status, const char* fmt, ...) __ATTR_PRINTF(2, 3) __ATTR_NORETURN;

#ifdef __cplusplus
}
#endif

#endif /* _ERR_H */
