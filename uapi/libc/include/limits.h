/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_LIMITS_H
#define _WA_LIBC_LIMITS_H

#include <wasmux/limits.h>

#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

#ifdef __CHAR_UNSIGNED__
# define CHAR_MIN 0
# define CHAR_MAX UCHAR_MAX
#else
# define CHAR_MIN SCHAR_MIN
# define CHAR_MAX SCHAR_MAX
#endif

#endif /* _WA_LIBC_LIMITS_H */
