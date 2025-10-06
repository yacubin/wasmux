/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/main_thread.h>
#include <wasmux/wei/worker_thread.h>

#ifdef WA_OS_WINDOWS
#include <wasmux/win32/MainThreadContext.h>
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
