/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_MMAN_H
#define _WASMUX_MMAN_H

#define MAP_TYPE      0x000f
#define MAP_FIXED     0x0010
#define MAP_ANONYMOUS 0x0020

/* mmap() prot */
#define PROT_NONE   0x00000000
#define PROT_READ   0x00000001
#define PROT_WRITE  0x00000002
#define PROT_EXEC   0x00000004

/* mmap() flags */
#define MAP_SHARED  0x00000001
#define MAP_PRIVATE 0x00000002

#define MADV_DONTNEED 4

#define MAP_HUGETLB    0x040000
#define MAP_HUGE_SHIFT 26
#define MAP_HUGE_MASK  0x3f

#endif /* _WASMUX_MMAN_H */
