/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

#include <wasmux/types.h>
#include <wasmux/posix_types.h>
#include <wasmux/time.h>

#ifdef __cplusplus
extern "C" {
#endif

#if __SIZEOF_LONG__ == 8
typedef unsigned long dev_t;
#else
typedef unsigned long long dev_t;
#endif

typedef uintptr_t nlink_t;
typedef long blksize_t;
typedef int blkcnt_t;

typedef unsigned char u_char;
typedef unsigned int u_int;
typedef unsigned short u_short;
typedef unsigned long u_long;

typedef uint8_t u_int8_t;
typedef uint16_t u_int16_t;
typedef uint32_t u_int32_t;

typedef short bits16_t;
typedef unsigned short u_bits16_t;
typedef int bits32_t;
typedef unsigned int u_bits32_t;
typedef uint64_t bits64_t;

typedef uint64_t ino_t;
typedef uint32_t id_t;

typedef unsigned useconds_t;

#ifdef __cplusplus
}
#endif

#endif /* _SYS_TYPES_H */
