/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/web/getcurrenttimer.h>
#include <wasmux/wei.h>

unsigned long WebGetCurrentTimer()
{
  return static_cast<unsigned long>(WEI_performanceNow() * 1000.0);
}
