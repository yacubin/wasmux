/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <wasmux/main_thread.h>
#include <wasmux/worker_thread.h>

#ifdef WA_OS_WINDOWS
#include <wasmux/windows/MainThreadContext.h>
void* g_mainInstance;
#endif

namespace WEI {

bool mainThreadInit()
{
#ifdef WA_OS_WINDOWS
  g_mainInstance = WebGetCurrentWorkerInstance();
  MainThreadContext::getInstance().objects().init();
#endif
  return true;
}

} // namespace WEI
