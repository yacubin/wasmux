/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>
#include "memory_heap.h"

#if defined(WA_OS_WINDOWS) || defined(WA_OS_LINUX)

#include <wasmux/wasm_page.h>

#include "host_alloc.h"

void memory_heap_init(struct memory_heap* thiz, size_t initial, size_t maximum)
{
  thiz->initial = initial;
  thiz->maximum = maximum;

  thiz->data = host_page_alloc(maximum);
  if (thiz->data) {
    thiz->base = (void*)((uintptr_t)thiz->data & WA_MEMORY_PAGE_MASK);
    thiz->end = (char*)thiz->base + thiz->initial * WA_MEMORY_PAGE_SIZE;
    thiz->size = thiz->initial;
  }
  else {
    thiz->base = NULL;
    thiz->end = NULL;
    thiz->size = 0;
  }
}

void memory_heap_release(struct memory_heap* thiz)
{
  if (thiz->data) {
    host_page_free(thiz->data);
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
