/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_WCHAR_H
#define _WA_LIBC_WCHAR_H

#include <stddef.h>
#include <wasmux/widechar.h>
#include <wasmux/stream.h>

#ifdef __cplusplus
extern "C" {
#endif

int wctob(wint_t wc);
wint_t btowc(int wc);
int iswalnum(wint_t wc);
int iswprint(wint_t wc);
int iswspace(wint_t wc);
wint_t towlower(wint_t wc);
wint_t towupper(wint_t wc);
int wcwidth(wchar_t wc);

// mbstate_s can be in <waf/mbstate.h> or another file
struct __glibc_mbstate_s {
  int __count;
};

typedef struct __glibc_mbstate_s mbstate_t;

int mbsinit(const mbstate_t* state);
size_t mbrtowc(wchar_t* wcs, const char* str, size_t len, mbstate_t* state);
size_t wcrtomb(char* str, wchar_t wcs, mbstate_t* state);
size_t mbrlen(const char* str, size_t len, mbstate_t* state);
size_t mbsrtowcs(wchar_t* dst, const char** src, size_t dstlen, mbstate_t* state);
size_t wcsrtombs(char* dst, const wchar_t** src, size_t dstlen, mbstate_t* state);

int wcscmp(const wchar_t* wcs1, const wchar_t* wcs2);
int wcsncmp(const wchar_t* wcs1, const wchar_t* wcs2, size_t len);
wchar_t* wmemcpy(wchar_t* wcs1, const wchar_t* wcs2, size_t len);
size_t wcslen(const wchar_t* wcs);
wchar_t* wcscat(wchar_t* dst, const wchar_t* src);
int wcswidth(const wchar_t* wcs, size_t len);
wchar_t* wcschr(const wchar_t* wcs, wchar_t wch);
wchar_t* wmemchr(const wchar_t* wcs, wchar_t wch, size_t len);
wchar_t* wcscpy(wchar_t* dst, const wchar_t* src);
int wcscoll(const wchar_t* wcs1, const wchar_t* wcs2);

wint_t putwc(wchar_t wc, FILE* stream);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_WCHAR_H */
