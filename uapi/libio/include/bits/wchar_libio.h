/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_WCHAR_LIBIO_H
#define _BITS_WCHAR_LIBIO_H

#include <wasmux/widechar.h>
#include <bits/file_struct.h>

#ifdef __cplusplus
extern "C" {
#endif

wint_t putwc(wchar_t wc, FILE* stream);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_WCHAR_LIBIO_H */
