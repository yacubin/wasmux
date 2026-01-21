/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_MM_H
#define _WASMUX_M_WASMUX_MM_HALLOC_H

#include <wasmux/types.h>
#include <wasmux/arch/mm.h>

#ifndef HAVE_ARCH_WASMUX_KMALLOC
static inline void* arch_wasmux_kmalloc(size_t size) { return NULL; }
#endif

#ifndef HAVE_ARCH_WASMUX_KFREE
static inline void arch_wasmux_kfree(void* ptr) { }
#endif

#ifndef HAVE_ARCH_WASMUX_ALLOC_PAGES
static inline void* arch_wasmux_alloc_pages(unsigned order) { return NULL; }
#endif

#ifndef HAVE_ARCH_WASMUX_FREE_PAGES
static inline void arch_wasmux_free_pages(void* page, unsigned order) { }
#endif

#define wasmux_kmalloc(size) arch_wasmux_kmalloc(size)
#define wasmux_kfree(ptr) arch_wasmux_kfree(ptr)
#define wasmux_alloc_pages(order) arch_wasmux_alloc_pages(order)
#define wasmux_free_pages(page, order) arch_wasmux_free_pages(page, order)

#endif /* _WASMUX_MM_H */
