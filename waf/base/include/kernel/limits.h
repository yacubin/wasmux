/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_LIMITS_H
#define _WA_KERNEL_LIMITS_H

#include <kernel/limits-base.h>

#define INT8_C      __INT_C
#define UINT8_C     __INT_C
#define INT16_C     __INT_C
#define UINT16_C    __INT_C
#define INT32_C     __INT_C
#define UINT32_C    __UINT_C

#if __SIZEOF_LONG__ == 8
# define INT64_C    __LONG_C
# define UINT64_C   __ULONG_C
#else
# define INT64_C    __LLONG_C
# define UINT64_C   __ULLONG_C
#endif

#define UINT8_MAX  (UINT8_C(255))
#define INT8_MAX   (INT8_C(127))
#define INT8_MIN   (-INT8_MAX - 1)

#define UINT16_MAX (UINT16_C(65535))
#define INT16_MAX  (INT16_C(32767))
#define INT16_MIN  (-INT16_MAX - 1)

#define UINT32_MAX (UINT32_C(4294967295))
#define INT32_MAX  (INT32_C(2147483647))
#define INT32_MIN  (-INT32_MAX - 1)

#define UINT64_MAX (UINT64_C(18446744073709551615))
#define INT64_MAX  (INT64_C(9223372036854775807))
#define INT64_MIN  (-INT64_MAX - 1)

#define UINTPTR_MAX ULONG_MAX
#define INTPTR_MAX LONG_MAX
#define INTPTR_MIN LONG_MIN

#define UINTMAX_MAX UINT64_MAX
#define INTMAX_MAX  INT64_MAX
#define INTMAX_MIN  INT64_MIN

#define SIZE_MAX    UINTPTR_MAX

#define SSIZE_MAX   INTPTR_MAX
#define SSIZE_MIN   INTPTR_MIN

#define PTRDIFF_MAX INTPTR_MAX
#define PTRDIFF_MIN INTPTR_MIN

#define PATH_MAX 4096  // Maximum length of a file path

#define CHAR_BIT 8
#define UCHAR_MAX 255

#endif /* _WA_KERNEL_LIMITS_H */
