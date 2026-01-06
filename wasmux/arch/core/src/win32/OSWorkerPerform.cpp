/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_WorkerPerform2(WEI_Object worker, void* callback, void* userdata)
{
  return -1;
}

extern "C" int os_WorkerPerform3(WEI_Object worker, void* callback, void* userdata, WEI_Object arg1)
{
  return -1;
}

extern "C" int os_WorkerPerform4(WEI_Object worker, void* callback, void* userdata, WEI_Object arg1, WEI_Object arg2)
{
  return -1;
}

extern "C" int os_WorkerPerform5(WEI_Object worker, void* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return -1;
}

#endif
