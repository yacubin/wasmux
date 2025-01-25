/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_MEMORY_ALLOC_H
#define _WASMUX_MEMORY_ALLOC_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void WebMemoryAllocInit();
void WebMemoryAllocExit();

void* WebMalloc(size_t size);
void* WebZeroMalloc(size_t size);
void WebFree(void* obj);

void* WebAllocPages(unsigned int order);
void WebFreePages(void* page, unsigned int order);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_MEMORY_ALLOC_H */
