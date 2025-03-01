/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LIBIO_WCHAR_H
#define _LIBIO_WCHAR_H

#include <bits/file_struct.h>
#include <wasmux/widechar.h>

#ifdef __cplusplus
extern "C" {
#endif

wint_t putwc(wchar_t wc, FILE* stream);

#ifdef __cplusplus
}
#endif

#endif /* _LIBIO_WCHAR_H */
