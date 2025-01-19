/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#pragma once

#include <wasmux/types.h>
#include <wasmux/wasm_symbols.h>

namespace WEI {

typedef uint32_t WasmMemoryIndex;
typedef uint32_t WasmTableIndex;

static constexpr WasmMemoryIndex kWasmCurrentMemory = 0;

template<WasmMemoryIndex memoryIndex>
class WasmHeap {
public:
  void* data() const { return &__memory_base; }
  void* heapBase() const { return &__heap_base; }
  void* heapEnd() const { return &__heap_end; }

  size_t size() const { return __builtin_wasm_memory_size(memoryIndex); }
  ssize_t grow(uint32_t delta) { return __builtin_wasm_memory_grow(memoryIndex, delta); }
};

using WasmCurrentHeap = WasmHeap<kWasmCurrentMemory>;

}  // namespace WEI
