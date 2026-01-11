/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei/memory_alloc.h>
#include <wasmux/wasm_page.h>
#include <wasmux/bulk-memory.h>

#include "memory_manager.h"

static wasmux::MemoryManager<WA_MEMORY_PAGE_SHIFT, WASMUX_CORE_INIT_PAGES, WASMUX_CORE_MAX_PAGES> s_memoryManager;

void WebMemoryAllocInit()
{
  s_memoryManager.init(WASMUX_CORE_INIT_PAGES, WASMUX_CORE_MAX_PAGES);
}

void WebMemoryAllocExit()
{
  s_memoryManager.release();
}

void* WebAllocPages(unsigned int order)
{
  return s_memoryManager.allocPages(order);
}

void WebFreePages(void* page, unsigned int order)
{
  s_memoryManager.freePages(page, order);
}

void* WebMalloc(size_t size)
{
  return s_memoryManager.malloc(size);
}

void* WebZeroMalloc(size_t size)
{
  void* ptr = WebMalloc(size);
  if (ptr) {
    kernel_memory_fill(ptr, 0, size);
  }
  return ptr;
}

void WebFree(void* ptr)
{
  s_memoryManager.free(ptr);
}
