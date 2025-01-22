/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS___STDLIB_H
#define _BITS___STDLIB_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void qsort(void* base, size_t n, size_t size, int (*compare) (const void*, const void*));
void qsort_r(void* base, size_t n, size_t size, int (*compare) (const void*, const void*, void*), void* arg);

#ifdef __cplusplus
}
#endif

#endif /* _BITS___STDLIB_H */
