/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" WEI_Object os_CallObjectMethod(WEI_Object object, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  return -1;
}

extern "C" int os_CallIntegerMethod(WEI_Object object, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  return -1;
}

#endif
