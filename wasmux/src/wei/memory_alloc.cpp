/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei/memory_alloc.h>

#include "memory_manager.h"

void WebMemoryAllocInit()
{
  memory_manager_init(&g_memory_manager);
}

void WebMemoryAllocExit()
{
  memory_manager_release(&g_memory_manager);
}

void* WebAllocPages(unsigned int order)
{
  return memory_manager_alloc_pages(&g_memory_manager, order);
}

void WebFreePages(void* page, unsigned int order)
{
  memory_manager_free_pages(&g_memory_manager, page, order);
}

void* WebMalloc(size_t size)
{
  return memory_manager_malloc(&g_memory_manager, size);
}

void* WebZeroMalloc(size_t size)
{
  void* ptr = memory_manager_malloc(&g_memory_manager, size);
  if (ptr) {
    kernel_memory_fill(ptr, 0, size);
  }
  return ptr;
}

void WebFree(void* ptr)
{
  memory_manager_free(&g_memory_manager, ptr);
}
