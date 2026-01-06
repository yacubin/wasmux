/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#define __SSIZE_T__ int // For windows.h

#include <wasmux-config.h>

#include <wasmux/win32/BaseThreadContext.h>

#include <wasmux/types.h>
#include <wasmux/wei/worker_thread.h>

#include <wasmux/win32/OSMalloc.h>
#include <wasmux/win32/MainThreadContext.h>
#include <wasmux/win32/WorkerThreadContext.h>

#include <windows.h>

namespace WEI {

BaseThreadContext& BaseThreadContext::getInstance()
{
  if (WebIsMainInstance())
    return MainThreadContext::getInstance();
  else
    return WorkerThreadContext::getInstance();
}

} // namespace WEI
