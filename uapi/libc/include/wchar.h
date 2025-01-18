/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WCHAR_H
#define _WCHAR_H

#include <stddef.h>
#include <wctype.h>
#include <wcsmbs.h>
#include <libio_wchar.h>
#include <wasmux/stream.h>

#ifdef __cplusplus
extern "C" {
#endif

int wcwidth(wchar_t wc);
int wcswidth(const wchar_t* wcs, size_t len);

int wcscoll(const wchar_t* wcs1, const wchar_t* wcs2);

#ifdef __cplusplus
}
#endif

#endif /* _WCHAR_H */
