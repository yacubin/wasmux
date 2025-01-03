/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_BULKMEMORY_H
#define _WA_KERNEL_BULKMEMORY_H

#include <kernel/types.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Copies a block of memory from one region to another
void* kernel_memory_copy(void* dst, const void* src, size_t n);

// Fills a block of memory with a specific value
void* kernel_memory_fill(void* dst, int ch, size_t n);

// Copies elements between tables
// kernel_table_copy -> table.copy

// Fills a table with repeated values
// kernel_table_fill -> table.fill

#ifdef __cplusplus
}
#endif

#endif /* _WA_KERNEL_BULKMEMORY_H */
