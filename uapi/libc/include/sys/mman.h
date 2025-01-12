/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

#include <wasmux/types.h>
#include <wasmux/mman.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MAP_FAILED ((void*)-1)

void* mmap(void* addr, size_t size, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t size);

int madvise (void* addr, size_t size, int advice);
int mprotect(void* addr, size_t size, int prot);
int mlock(const void* addr, size_t size);
int munlock(const void* addr, size_t size);
void* mremap(void* old_addr, size_t old_size, size_t new_size, int flags, ...);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_MMAN_H */
