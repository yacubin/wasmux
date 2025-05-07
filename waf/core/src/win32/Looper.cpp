/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <wasmux/win32/Looper.h>
#include <wasmux/win32/BaseThreadContext.h>

namespace WEI {

void Looper::run()
{
}

bool Looper::call(WEI_PerformCallback* dispatchCallback, void* userdata)
{
  return false;
}

void currentLooperRun()
{
  return BaseThreadContext::getInstance().looper().run();
}

bool currentLooperCall(WEI_PerformCallback* dispatchCallback, void* userdata)
{
  return BaseThreadContext::getInstance().looper().call(dispatchCallback, userdata);
}

} // namespace WEI
