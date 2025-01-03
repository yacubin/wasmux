/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_MMAN_H
#define _WA_LIBC_SYS_MMAN_H

#include <kernel/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* mmap() prot */
#define PROT_NONE   0x00000000
#define PROT_READ   0x00000001
#define PROT_WRITE  0x00000002
#define PROT_EXEC   0x00000004

/* mmap() flags */
#define MAP_SHARED  0x00000001
#define MAP_PRIVATE 0x00000002

#define MAP_FAILED ((void*)-1)

void* mmap(void* addr, size_t size, int prot, int flags, int fd, off_t offset);
int munmap(void* addr, size_t size);

int mprotect(void* addr, size_t size, int prot);
int mlock(const void* addr, size_t size);
int munlock(const void* addr, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_MMAN_H */
