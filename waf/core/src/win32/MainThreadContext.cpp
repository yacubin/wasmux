/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <wasmux/win32/MainThreadContext.h>

namespace WEI {

static MainThreadContext s_mainInstance;

MainThreadContext& MainThreadContext::getInstance()
{
  return s_mainInstance;
}

} // namespace WEI
