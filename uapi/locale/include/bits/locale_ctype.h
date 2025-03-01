/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_LOCALE_CTYPE_H
#define _BITS_LOCALE_CTYPE_H

#include <bits/locale_struct.h>

#ifdef __cplusplus
extern "C" {
#endif

int isalnum_l(int ch, locale_t locale);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_LOCALE_CTYPE_H */
