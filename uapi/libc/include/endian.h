/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _ENDIAN_H
#define _ENDIAN_H

#include <wasmux/swab.h>

#define __LITTLE_ENDIAN 1234
#define __BIG_ENDIAN    4321

#define __BYTE_ORDER __LITTLE_ENDIAN

#define __idle16(x) (uint16_t)(x)
#define __idle32(x) (uint32_t)(x)
#define __idle64(x) (uint64_t)(x)

#define htobe16 __swab16
#define htole16 __idle16
#define be16toh __swab16
#define le16toh __idle16

#define htobe32 __swab32
#define htole32 __idle32
#define be32toh __swab32
#define le32toh __idle32

#define htobe64 __swab64
#define htole64 __idle64
#define be64toh __swab64
#define le64toh __idle64

#endif /* _ENDIAN_H */
