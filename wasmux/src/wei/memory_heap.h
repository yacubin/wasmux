/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/export.h>
#include <wasmux/platform.h>

#if defined(WA_CPU_WASM)

#include <wasmux/wasm_symbols.h>

#define MEMORY_HEAP_INDEX (0)

struct memory_heap {
};

static inline void memory_heap_init(struct memory_heap* thiz, size_t initial, size_t maximum)
{
}

static inline void memory_heap_release(struct memory_heap* thiz)
{
}

static inline void* memory_heap_data(const struct memory_heap* thiz)
{
  return &__memory_base;
}

static inline void* memory_heap_base(const struct memory_heap* thiz)
{
  return &__heap_base;
}

static inline void* memory_heap_end(const struct memory_heap* thiz)
{
  return &__heap_end;
}

static inline size_t memory_heap_size(const struct memory_heap* thiz)
{
  return __builtin_wasm_memory_size(MEMORY_HEAP_INDEX);
}

static inline ssize_t memory_heap_grow(struct memory_heap* thiz, uint32_t delta)
{
  return __builtin_wasm_memory_grow(MEMORY_HEAP_INDEX, delta);
}

#elif defined(WA_OS_WINDOWS)

struct memory_heap {
  void* data;
  void* base;
  void* end;
  size_t initial;
  size_t maximum;
  size_t size;
};

__EXPORT void memory_heap_init(struct memory_heap*, size_t initial, size_t maximum);
__EXPORT void memory_heap_release(struct memory_heap*);

static inline void* memory_heap_data(const struct memory_heap* thiz)
{
  return thiz->data;
}

static inline void* memory_heap_base(const struct memory_heap* thiz)
{
  return thiz->base;
}

static inline void* memory_heap_end(const struct memory_heap* thiz)
{
  return thiz->end;
}

static inline size_t memory_heap_size(const struct memory_heap* thiz)
{
  return thiz->size;
}

__EXPORT ssize_t memory_heap_grow(struct memory_heap* thiz, uint32_t delta);

#else

struct memory_heap {
};

static inline void memory_heap_init(struct memory_heap* thiz, size_t initial, size_t maximum)
{
}

static inline void memory_heap_release(struct memory_heap* thiz)
{
}

static inline void* memory_heap_data(const struct memory_heap* thiz)
{
  return NULL;
}

static inline void* memory_heap_base(const struct memory_heap* thiz)
{
  return NULL;
}

static inline void* memory_heap_end(const struct memory_heap* thiz)
{
  return NULL;
}

static inline size_t memory_heap_size(const struct memory_heap* thiz)
{
  return 0;
}

static inline ssize_t memory_heap_grow(struct memory_heap* thiz, uint32_t delta)
{
  return -1;
}

#endif
