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
#define IOV_MAX 1024

/* Max length of a login username (including NIL) */
#define LOGIN_NAME_MAX 256

/* Maximum number of bytes in a character class name */
#define CHARCLASS_NAME_MAX 14

/* Max repetitions allowed for {m,n} in POSIX regular expressions */
#define RE_DUP_MAX 255

/* Max length of terminal device name */
#define TTY_NAME_MAX 32

#endif /* _LIMITS_H */
