/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SWAB_H
#define _WASMUX_SWAB_H

#include <wasmux/types.h>

#define __swab16(x) (uint16_t)__builtin_bswap16((uint16_t)(x))
#define __swab32(x) (uint32_t)__builtin_bswap32((uint32_t)(x))
#define __swab64(x) (uint64_t)__builtin_bswap64((uint64_t)(x))

#endif /* _WASMUX_SWAB_H */
