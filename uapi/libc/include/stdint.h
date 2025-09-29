/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _STDINT_H
#define _STDINT_H

#include <wasmux/types.h>
#include <wasmux/limits.h>

typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;

# if defined(__wasm64__)
typedef long int_fast16_t;
typedef long int_fast32_t;
typedef long int_fast64_t;
#else
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int_fast64_t;
#endif

# if defined(__wasm64__)
typedef unsigned long uint_fast16_t;
typedef unsigned long uint_fast32_t;
typedef unsigned long uint_fast64_t;
#else
typedef unsigned uint_fast16_t;
typedef unsigned uint_fast32_t;
typedef unsigned long long uint_fast64_t;
#endif

typedef int8_t   int_least8_t;
typedef int16_t  int_least16_t;
typedef int32_t  int_least32_t;
typedef int64_t  int_least64_t;

typedef uint8_t  uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

#endif /* _STDINT_H */
