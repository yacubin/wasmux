/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_WorkerPerform(WEI_Object worker, void* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return -1;
}

#endif
