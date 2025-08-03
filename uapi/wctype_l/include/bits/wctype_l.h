/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_WCTYPE_L_H
#define _BITS_WCTYPE_L_H

#include <wasmux/widechar.h>
#include <locale.h>

#ifdef __cplusplus
extern "C" {
#endif

int iswctype_l(wint_t wc, wctype_t charclass, locale_t locale);
wctype_t wctype_l(const char* name, locale_t locale);

int iswupper_l(wint_t wc, locale_t locale);
int iswlower_l(wint_t wc, locale_t locale);
int iswalnum_l(wint_t wc, locale_t locale);
int iswprint_l(wint_t wc, locale_t locale);
int iswspace_l(wint_t wc, locale_t locale);
int iswdigit_l(wint_t wc, locale_t locale);
int iswalpha_l(wint_t wc, locale_t locale);
int iswblank_l(wint_t wc, locale_t locale);
int iswcntrl_l(wint_t wc, locale_t locale);
int iswgraph_l(wint_t wc, locale_t locale);
int iswpunct_l(wint_t wc, locale_t locale);
int iswxdigit_l(wint_t wc, locale_t locale);

wint_t towlower_l(wint_t wc, locale_t locale);
wint_t towupper_l(wint_t wc, locale_t locale);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_WCTYPE_L_H */
