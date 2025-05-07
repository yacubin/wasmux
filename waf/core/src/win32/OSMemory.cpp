/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" WEI_Object os_MemoryCreate(unsigned initial, unsigned maximum, bool shared)
{
  return WEI_UNDEFINED_OBJECT;
}

extern "C" unsigned os_MemoryCopy(WEI_Object dstMemory, void* dstData, WEI_Object srcMemory, const void* srcData, unsigned size)
{
  return 0;
}

extern "C" unsigned os_MemorySize(WEI_Object memory)
{
  return 0;
}

extern "C" unsigned os_MemoryGrow(WEI_Object memory, unsigned delta)
{
  return 0;
}

extern "C" unsigned os_MemoryStrnlen(WEI_Object memory, const char* str, long n)
{
  return 0;
}

extern "C" unsigned os_MemoryFill(WEI_Object memory, void* ptr, int val, unsigned len)
{
  return 0;
}

extern "C" unsigned os_MemoryStrncpy(WEI_Object dstMemory, char* dst, WEI_Object srcMemory, const char* src, unsigned count)
{
  return 0;
}

#endif
