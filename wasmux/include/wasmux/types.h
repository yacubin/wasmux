/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_TYPES_H
#define _WASMUX_TYPES_H

#include <wasmux/sizeof.h>

#if defined(__ASSEMBLY__)
#if __SIZEOF_VOIDP__ == 8
#  define PTR i64
#  define PTR_SIZE 8
# else
#  define PTR i32
#  define PTR_SIZE 4
# endif
#else

# include <wasmux/nullptr.h>
# include <wasmux/int-types.h>

# define __PRIPTR_PREFIX "l"

#if __SIZEOF_LONG__ == 8
# define __PRI64_PREFIX "l"
#else
# define __PRI64_PREFIX "ll"
#endif

# ifndef __SSIZE_T__
#  define __SSIZE_T__ long
# endif

typedef __SSIZE_T__ ssize_t;
typedef unsigned __SSIZE_T__ size_t;

typedef ssize_t intptr_t;
typedef size_t uintptr_t;

typedef int64_t intmax_t;
typedef uint64_t uintmax_t;

typedef intptr_t ptrdiff_t;

typedef int pid_t;
typedef unsigned uid_t;
typedef unsigned gid_t;
typedef int64_t off64_t;

typedef intptr_t off_t;

#if __SIZEOF_LONG__ == 8
// typedef long off_t;
typedef long loff_t;
#else
// typedef long long off_t;
typedef long long loff_t;
#endif

typedef int clockid_t;
typedef unsigned int mode_t;
typedef unsigned short umode_t;

#endif

#endif /* _WASMUX_TYPES_H */
