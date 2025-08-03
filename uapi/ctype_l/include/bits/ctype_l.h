/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_CTYPE_L_H
#define _BITS_CTYPE_L_H

#include <locale.h>

#ifdef __cplusplus
extern "C" {
#endif

int toupper_l(int ch, locale_t locale);
int tolower_l(int ch, locale_t locale);

int isalpha_l(int ch, locale_t locale);
int isalnum_l(int ch, locale_t locale);
int iscntrl_l(int ch, locale_t locale);
int isdigit_l(int ch, locale_t locale);
int isgraph_l(int ch, locale_t locale);
int islower_l(int ch, locale_t locale);
int isprint_l(int ch, locale_t locale);
int ispunct_l(int ch, locale_t locale);
int isspace_l(int ch, locale_t locale);
int isupper_l(int ch, locale_t locale);
int isxdigit_l(int ch, locale_t locale);

int isblank_l(int ch, locale_t locale);
int isascii_l(int ch, locale_t locale);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_CTYPE_L_H */
