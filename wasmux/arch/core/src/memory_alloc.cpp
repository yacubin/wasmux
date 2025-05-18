/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS
#define __SSIZE_T__ int // For windows.h
#endif

#include <wasmux/memory_alloc.h>
#include <wasmux/wasm_page.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/cxx/StaticStorage.h>
#include <wasmux/cxx/MemoryManager.h>

#ifdef WA_CPU_WASM
#include <wasmux/cxx/WasmHeap.h>
using MemoryManagerHeap = WEI::WasmCurrentHeap;
#else
#include <wasmux/cxx/HostHeap.h>
using MemoryManagerHeap = WEI::HostHeap;
#endif

using WasmMemoryManager = WAF::MemoryManager<WA_MEMORY_PAGE_SHIFT, WASMUX_CORE_INIT_PAGES, WASMUX_CORE_MAX_PAGES, MemoryManagerHeap>;

static StaticStorage<MemoryManagerHeap> s_heap;
static StaticStorage<WasmMemoryManager> s_memoryManager;

void WebMemoryAllocInit()
{
#ifdef WA_CPU_WASM
  s_heap.initialize();
#else
  s_heap.initialize(WASMUX_CORE_INIT_PAGES, WASMUX_CORE_MAX_PAGES);
#endif
  s_memoryManager.initialize(*s_heap);
}

void WebMemoryAllocExit()
{
  s_memoryManager.finalize();
  s_heap.finalize();
}

void* WebAllocPages(unsigned int order)
{
  return s_memoryManager->allocPages(order);
}

void WebFreePages(void* page, unsigned int order)
{
  s_memoryManager->freePages(page, order);
}

void* WebMalloc(size_t size)
{
  return s_memoryManager->malloc(size);
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
  s_memoryManager->free(ptr);
}
