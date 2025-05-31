/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>
#include <wasmux/win32/WorkerThreadContext.h>

#include <wasmux/platform.h>
#include <wasmux/worker_thread.h>
#include <wasmux/cxx/New.h>
#include <wasmux/win32/OSMalloc.h>

namespace WEI {

WorkerThreadContext* WorkerThreadContext::create()
{
  void* ptr = OSMalloc(sizeof(WorkerThreadContext));
  if (ptr == nullptr) {
    // LOG
    return nullptr;
  }
  return new (wasmux::CtorOnly, ptr) WorkerThreadContext();
}

void WorkerThreadContext::destroy(WorkerThreadContext*)
{
}

WorkerThreadContext& WorkerThreadContext::getInstance()
{
  WebWorkerInstance* instance = WebGetCurrentWorkerInstance();
  return *reinterpret_cast<WorkerThreadContext*>(instance->context);
}

} // namespace WEI
