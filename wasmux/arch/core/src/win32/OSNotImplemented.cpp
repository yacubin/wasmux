/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

extern "C" int os_NotImplemented()
{
  return -1;
}

#endif
