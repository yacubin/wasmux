/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_WCHAR_H
#define _BITS_WCHAR_H

#include <wasmux/types.h>
#include <wasmux/widechar.h>

#ifdef __cplusplus
extern "C" {
#endif

int wcwidth(wchar_t wc);
int wcswidth(const wchar_t* wcs, size_t len);

int wcscoll(const wchar_t* wcs1, const wchar_t* wcs2);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_WCHAR_H */
