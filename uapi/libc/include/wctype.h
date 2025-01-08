/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_WCTYPE_H
#define _WA_LIBC_WCTYPE_H

#include <wasmux/widechar.h>

#ifdef __cplusplus
extern "C" {
#endif

wctype_t wctype(const char* name);
int iswctype(wint_t wc, wctype_t charclass);
int iswupper(wint_t wc);
int iswlower(wint_t wc);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_WCTYPE_H */
