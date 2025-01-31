/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LIMITS_H
#define _LIMITS_H

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

#define MB_LEN_MAX 4
#define NL_ARGMAX 9

/* Max length of a login username (including NIL) */
#define LOGIN_NAME_MAX 256

#endif /* _LIMITS_H */
