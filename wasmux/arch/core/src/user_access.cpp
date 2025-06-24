/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/user_access.h>
#include <wasmux/web/object.h>
#include <wasmux/worker_instance.h>
#include <wasmux/cxx/ObjectCast.h>

unsigned long WebCopyFromUserMemory(void* to, const void* from, unsigned long n)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryCopy(WEI_KERNEL_MEMORY_ID, to, object_idx_cast(instance->userMemory), from, n);
}

unsigned long WebCopyToUserMemory(void* to, const void* from, unsigned long n)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryCopy(object_idx_cast(instance->userMemory), to, WEI_KERNEL_MEMORY_ID, from, n);
}

long WebStrncpyFromUser(char* dst, const char* src, long count)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryStrncpy(WEI_KERNEL_MEMORY_ID, dst, object_idx_cast(instance->userMemory), src, count);
}

long WebStrnlenUserMemory(const char* str, long n)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryStrnlen(object_idx_cast(instance->userMemory), str, n);
}

unsigned long WebClearUserMemory(void* mem, unsigned long len)
{
  struct WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return WEI_memoryFill(object_idx_cast(instance->userMemory), mem, 0, len);
}
