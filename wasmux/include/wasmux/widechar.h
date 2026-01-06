/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WIDECHAR_H
#define _WASMUX_WIDECHAR_H

#define WEOF (0xffffffffU)

typedef unsigned wint_t;
typedef unsigned long wctype_t;

# ifndef __cplusplus
#  ifdef __WCHAR_TYPE__
typedef __WCHAR_TYPE__ wchar_t;
#  elif defined(_WIN32) || defined(_WIN64)
typedef unsigned short wchar_t;
#  else
typedef unsigned wchar_t;
#  endif
# endif

#endif /* _WASMUX_WIDECHAR_H */
