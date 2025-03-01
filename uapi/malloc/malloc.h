/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _MALLOC_H
#define _MALLOC_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void* malloc(size_t size);
void* calloc(size_t num, size_t size);
void* realloc(void* ptr, size_t size);
void free(void* ptr);

void* aligned_alloc(size_t alignment, size_t size);
int posix_memalign(void** mem, size_t alignment, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* _MALLOC_H */
