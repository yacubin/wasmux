/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include "BaseThreadContext.h"

#include <wasmux/types.h>
#include <wasmux/worker_thread.h>

#include "OSMalloc.h"
#include "MainThreadContext.h"
#include "WorkerThreadContext.h"

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
