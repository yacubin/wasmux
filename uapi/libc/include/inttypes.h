/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PRI of int8_t and uint8_t */
#define PRId8 "d"
#define PRIi8 "i"
#define PRIo8 "o"
#define PRIu8 "u"
#define PRIx8 "x"
#define PRIX8 "X"

/* PRI of int16_t and uint16_t */
#define PRId16 "d"
#define PRIi16 "i"
#define PRIo16 "o"
#define PRIu16 "u"
#define PRIx16 "x"
#define PRIX16 "X"

/* PRI of int32_t and uint32_t */
#define PRId32 "d"
#define PRIi32 "i"
#define PRIo32 "o"
#define PRIu32 "u"
#define PRIx32 "x"
#define PRIX32 "X"

/* PRI of int64_t and uint64_t */
#define PRId64 __PRI64_PREFIX "d"
#define PRIi64 __PRI64_PREFIX "i"
#define PRIo64 __PRI64_PREFIX "o"
#define PRIu64 __PRI64_PREFIX "u"
#define PRIx64 __PRI64_PREFIX "x"
#define PRIX64 __PRI64_PREFIX "X"

/* PRI of intmax_t and uintmax_t */
#define PRIdMAX __PRI64_PREFIX "d"
#define PRIiMAX __PRI64_PREFIX "i"
#define PRIoMAX __PRI64_PREFIX "o"
#define PRIuMAX __PRI64_PREFIX "u"
#define PRIxMAX __PRI64_PREFIX "x"
#define PRIXMAX __PRI64_PREFIX "X"

/* PRI of intptr_t and uintptr_t */
#define PRIdPTR __PRIPTR_PREFIX "d"
#define PRIiPTR __PRIPTR_PREFIX "i"
#define PRIoPTR __PRIPTR_PREFIX "o"
#define PRIuPTR __PRIPTR_PREFIX "u"
#define PRIxPTR __PRIPTR_PREFIX "x"
#define PRIXPTR __PRIPTR_PREFIX "X"

/* SCN of int64_t and uint64_t */
#define SCNd64 __PRI64_PREFIX "d"
#define SCNi64 __PRI64_PREFIX "i"
#define SCNo64 __PRI64_PREFIX "o"
#define SCNu64 __PRI64_PREFIX "u"
#define SCNx64 __PRI64_PREFIX "x"

intmax_t strtoimax(const char* str, char** end, int base);
uintmax_t strtoumax(const char* str, char** end, int base);

#ifdef __cplusplus
}
#endif

#endif /* _INTTYPES_H */
