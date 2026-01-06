/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_INT_TYPES_H
#define _WASMUX_INT_TYPES_H

#include <wasmux/sizeof.h>

typedef signed char int8_t;
typedef unsigned char uint8_t;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned uint32_t;

#if __SIZEOF_LONG__ == 8
typedef long int64_t;
typedef unsigned long uint64_t;
#else
typedef long long int64_t;
typedef unsigned long long uint64_t;
#endif

#endif /* _WASMUX_INT_TYPES_H */
