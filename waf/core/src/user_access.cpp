/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/user_access.h>
#include <wasmux/web/object.h>
#include <wasmux/worker_instance.h>

unsigned long WebCopyFromUserMemory(void* to, const void* from, unsigned long n)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryCopy(WEI_KERNEL_MEMORY_ID, to, instance->userMemory, from, n);
}

unsigned long WebCopyToUserMemory(void* to, const void* from, unsigned long n)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryCopy(instance->userMemory, to, WEI_KERNEL_MEMORY_ID, from, n);
}

long WebStrncpyFromUser(char* dst, const char* src, long count)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryStrncpy(WEI_KERNEL_MEMORY_ID, dst, instance->userMemory, src, count);
}

long WebStrnlenUserMemory(const char* str, long n)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryStrnlen(instance->userMemory, str, n);
}

unsigned long WebClearUserMemory(void* mem, unsigned long len)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryFill(instance->userMemory, mem, 0, len);
}
