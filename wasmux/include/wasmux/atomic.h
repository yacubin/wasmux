/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ATOMIC_H
#define _WASMUX_ATOMIC_H

#include <wasmux/compiler.h>
#include <wasmux/types.h>

struct wasmux_atomic32_t {
  int32_t counter;
};

static __ATTR_ALWAYS_INLINE int wasmux_atomic32_load(const wasmux_atomic32_t* atomic)
{
	return __atomic_load_n(&atomic->counter, __ATOMIC_SEQ_CST);
}

static __ATTR_ALWAYS_INLINE void wasmux_atomic32_store(wasmux_atomic32_t* atomic, int value)
{
  __atomic_store_n(&atomic->counter, value, __ATOMIC_SEQ_CST);
}

static __ATTR_ALWAYS_INLINE int wasmux_atomic32_add_fetch(wasmux_atomic32_t* atomic, int value)
{
  return __atomic_add_fetch(&atomic->counter, value, __ATOMIC_SEQ_CST);
}

static __ATTR_ALWAYS_INLINE int wasmux_atomic32_fetch_add(wasmux_atomic32_t* atomic, int value)
{
  return __atomic_fetch_add(&atomic->counter, value, __ATOMIC_SEQ_CST);
}

struct wasmux_atomic64_t {
  int64_t counter;
};

static __ATTR_ALWAYS_INLINE int wasmux_atomic64_load(const wasmux_atomic64_t* atomic)
{
	return __atomic_load_n(&atomic->counter, __ATOMIC_SEQ_CST);
}

static __ATTR_ALWAYS_INLINE void wasmux_atomic64_store(wasmux_atomic64_t* atomic, int value)
{
  __atomic_store_n(&atomic->counter, value, __ATOMIC_SEQ_CST);
}

static __ATTR_ALWAYS_INLINE int wasmux_atomic64_add_fetch(wasmux_atomic64_t* atomic, int value)
{
  return __atomic_add_fetch(&atomic->counter, value, __ATOMIC_SEQ_CST);
}

static __ATTR_ALWAYS_INLINE int wasmux_atomic64_fetch_add(wasmux_atomic64_t* atomic, int value)
{
  return __atomic_fetch_add(&atomic->counter, value, __ATOMIC_SEQ_CST);
}

#endif /* _WASMUX_ATOMIC_H */
