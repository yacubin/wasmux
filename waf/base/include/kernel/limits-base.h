/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_LIMITS_BASE_H
#define _WA_KERNEL_LIMITS_BASE_H

#include <kernel/sizeof.h>

#define __UINT_C(c)   c ## U
#define __INT_C(c)    c
#define __ULONG_C(c)  c ## UL
#define __LONG_C(c)   c ## L
#define __ULLONG_C(c) c ## ULL
#define __LLONG_C(c)  c ## LL

#define USHRT_MAX  (0xffff)
#define SHRT_MAX   (0x7fff)
#define SHRT_MIN   (-SHRT_MAX - 1)

#define UINT_MAX   (0xffffffffU)
#define INT_MAX    (0x7fffffff)
#define INT_MIN    (-INT_MAX - 1)

#define ULLONG_MAX (0xffffffffffffffffULL)
#define LLONG_MAX  (0x7fffffffffffffffLL)
#define LLONG_MIN  (-LLONG_MAX - 1LL)

#if __SIZEOF_LONG__ == 8
# define ULONG_MAX (0xffffffffffffffffUL)
# define LONG_MAX  (0x7fffffffffffffffL)
#else
# define ULONG_MAX (0xffffffffUL)
# define LONG_MAX  (0x7fffffffL)
#endif

#define LONG_MIN   (-LONG_MAX -1L)

#endif /* _WA_KERNEL_LIMITS_BASE_H */
