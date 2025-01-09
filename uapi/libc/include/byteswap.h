/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BYTESWAP_H
#define _BYTESWAP_H

#include <wasmux/swab.h>

#define bswap_16 __swab16
#define bswap_32 __swab32
#define bswap_64 __swab64

#endif /* _BYTESWAP_H */
