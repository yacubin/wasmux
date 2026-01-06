/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/getrandombytes.h>
#include <wasmux/bulk-memory.h>
#include <wasmux/wei.h>

size_t WebGetRandomBytes(void* buf, size_t len)
{
  size_t result = 0;
  uint8_t* ptr = static_cast<uint8_t*>(buf);

  while (len > 0) {
    double value = WEI_mathRandom();
    size_t size = (len < 6) ? len : 6;
    kernel_memory_copy(ptr, &value, size);
    len -= size;
    result += size;
  }

  return result;
}
