/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/platform.h>

#ifdef WA_OS_WINDOWS

#define __WEBCALL(nr, sym) extern "C" int os_##sym(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
#include <wasmux/webcall-main.h>
#include <wasmux/webcall-worker.h>
#undef __WEBCALL

#define __WEBCALL(nr, sym) &os_##sym,
static WEI_CallFunction* s_mainCalls[] = {
#include <wasmux/webcall-main.h>
};
static WEI_CallFunction* s_workerCalls[] = {
#include <wasmux/webcall-worker.h>
};
#undef __WEBCALL

int WEI_webcall(unsigned number, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4, unsigned arg5, unsigned arg6)
{
  return s_mainCalls[number](arg1, arg2, arg3, arg4, arg5, arg6);
}

#endif
