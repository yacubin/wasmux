/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/platform.h>

#if defined(WA_CPU_WASM)

#include <wasmux/wasm_symbols.h>

namespace WEI {

typedef uint32_t WasmMemoryIndex;
typedef uint32_t WasmTableIndex;

static constexpr WasmMemoryIndex kWasmCurrentMemory = 0;

template<WasmMemoryIndex memoryIndex>
class WasmHeap {
public:
  WasmHeap(size_t initial, size_t maximum) {}

  void* data() const { return &__memory_base; }
  void* heapBase() const { return &__heap_base; }
  void* heapEnd() const { return &__heap_end; }

  size_t size() const { return __builtin_wasm_memory_size(memoryIndex); }
  ssize_t grow(uint32_t delta) { return __builtin_wasm_memory_grow(memoryIndex, delta); }
};

using WasmCurrentHeap = WasmHeap<kWasmCurrentMemory>;

}  // namespace WEI

using MemoryManagerHeap = WEI::WasmCurrentHeap;

#elif defined(WA_OS_WINDOWS)

namespace WEI {

class HostHeap {
public:
  HostHeap(size_t initial, size_t maximum);
  ~HostHeap();

  void* data() const { return m_data; }
  void* heapBase() const { return m_heapBase; }
  void* heapEnd() const { return m_heapEnd; }

  size_t size() const { return m_size; }
  ssize_t grow(uint32_t delta);

private:
  void* m_data;
  void* m_heapBase;
  void* m_heapEnd;
  size_t m_initial;
  size_t m_maximum;
  size_t m_size;
};

} // namespace WEI

using MemoryManagerHeap = WEI::HostHeap;

#endif
