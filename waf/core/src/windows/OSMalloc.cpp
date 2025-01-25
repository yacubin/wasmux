/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include "OSMalloc.h"
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

#include <windows.h>

namespace WEI {

void* OSMalloc(size_t size)
{
  return HeapAlloc(GetProcessHeap(), 0, size);
}

void* OSZeroMalloc(size_t size)
{
  return HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size);
}

void OSFree(void* ptr)
{
  HeapFree(GetProcessHeap(), 0, ptr);
}

} // namespace WEI

#endif
