/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEI_MEMORY_MANAGER_H
#define _WASMUX_WEI_MEMORY_MANAGER_H

#include <wasmux/wasm_page.h>
#include <wasmux/types.h>
#include <wasmux/export.h>
#include <wasmux/mutex.h>
#include <wasmux/bitset.h>

#include "memory_heap.h"

#define WA_MEMORY_MANAGER_PAGE_SIZE (1 << WA_MEMORY_PAGE_SHIFT)
#define WA_MEMORY_MANAGER_SBLOCK_SHIFT (12)
#define WA_MEMORY_MANAGER_SBLOCK_SIZE ((1 << WA_MEMORY_MANAGER_SBLOCK_SHIFT) - sizeof(void*))
#define WA_MEMORY_MANAGER_SBLOCKINPAGE (1 << (WA_MEMORY_PAGE_SHIFT - WA_MEMORY_MANAGER_SBLOCK_SHIFT))

struct memory_manager {
  struct memory_heap heap;
  wa_mutex_t mutex;
  WASMUX_BITSET_DEFINE(bblock_pages, WASMUX_CORE_MAX_PAGES);
  WASMUX_BITSET_DEFINE(sblock_pages, WASMUX_CORE_MAX_PAGES);

  unsigned index_base;
  unsigned index_start;
  unsigned index_stop;

  unsigned free_pages;
  unsigned free_blocks;
};

__EXPORT struct memory_manager g_memory_manager;

struct memory_manager_metrics {
  unsigned free_pages;
  unsigned free_blocks;
};

__EXPORT void memory_manager_init(struct memory_manager*);
__EXPORT void memory_manager_release(struct memory_manager*);

__EXPORT void* memory_manager_alloc_pages(struct memory_manager*, unsigned int order);
__EXPORT void memory_manager_free_pages(struct memory_manager*, void* page, unsigned int order);

__EXPORT void* memory_manager_malloc(struct memory_manager*, size_t size);
__EXPORT void memory_manager_free(struct memory_manager*, void* ptr);

__EXPORT bool memory_manager_addr_valid(const struct memory_manager*, void* ptr);
__EXPORT void memory_manager_get_metrics(struct memory_manager*, struct memory_manager_metrics* metrics);

#endif /* _WASMUX_WEI_MEMORY_MANAGER_H */
