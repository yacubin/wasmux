/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>
#include "memory_heap.h"

#if defined(WA_OS_WINDOWS)

#include <windows.h>

#include <wasmux/log.h>
#include <wasmux/wasm_page.h>

void memory_heap_init(struct memory_heap* thiz, size_t initial, size_t maximum)
{
  thiz->initial = initial;
  thiz->maximum = maximum;

  thiz->data = VirtualAlloc(NULL, (maximum + 1) * WA_MEMORY_PAGE_SIZE,
                        MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (thiz->data) {
    thiz->base = (void*)((uintptr_t)thiz->data & WA_MEMORY_PAGE_MASK);
    thiz->end = (char*)thiz->base + thiz->initial * WA_MEMORY_PAGE_SIZE;
    thiz->size = thiz->initial;
  }
  else {
    LOG_ERROR("Can't allocate memory (%u)", (unsigned)GetLastError());
    thiz->base = NULL;
    thiz->end = NULL;
    thiz->size = 0;
  }
}

void memory_heap_release(struct memory_heap* thiz)
{
  if (thiz->data) {
    VirtualFree(thiz->data, 0, MEM_RELEASE);
  }
}

ssize_t memory_heap_grow(struct memory_heap* thiz, uint32_t delta)
{
  ssize_t result = thiz->size;
  if (delta) {
    ssize_t newSize = thiz->size + delta;
    if (newSize < thiz->size || thiz->maximum < newSize) {
      return -1;
    }
    thiz->end = (char*)thiz->end + delta * WA_MEMORY_PAGE_SIZE;
    thiz->size = newSize;
  }
  return result;
}

#endif
