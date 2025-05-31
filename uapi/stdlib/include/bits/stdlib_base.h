/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_STDLIB_BASE_H
#define _BITS_STDLIB_BASE_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

int abs(int i);
long labs(long i);
long long llabs(long long i);

void qsort(void* base, size_t n, size_t size, int (*compare) (const void*, const void*));
void qsort_r(void* base, size_t n, size_t size, int (*compare) (const void*, const void*, void*), void* arg);

int mkostemp(char* pattern, int flags);
char* realpath(const char* filename, char* resolved);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_STDLIB_BASE_H */
