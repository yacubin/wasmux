/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/memory_alloc.h>

__ATTR_EXPORT_NAME("perform") __ATTR_USED
void _perform_kernel(long callbackAddr, long userdataAddr, long arg1, long arg2, long arg3, long arg4)
{
  if (callbackAddr) {
    auto userdata = reinterpret_cast<void*>(userdataAddr);
    if (!arg1) {
      auto callback = reinterpret_cast<WEI_PerformCallback*>(callbackAddr);
      callback(userdata);
    }
    else if (!arg2) {
      auto callback = reinterpret_cast<WEI_PerformCallback1*>(callbackAddr);
      callback(userdata, static_cast<WEI_Object>(arg1));
    }
    else if (!arg3) {
      auto callback = reinterpret_cast<WEI_PerformCallback2*>(callbackAddr);
      callback(userdata, static_cast<WEI_Object>(arg1), static_cast<WEI_Object>(arg2));
    }
    else if (!arg4) {
      auto callback = reinterpret_cast<WEI_PerformCallback3*>(callbackAddr);
      callback(userdata, static_cast<WEI_Object>(arg1), static_cast<WEI_Object>(arg2), static_cast<WEI_Object>(arg3));
    }
    else {
      auto callback = reinterpret_cast<WEI_PerformCallback4*>(callbackAddr);
      callback(userdata, static_cast<WEI_Object>(arg1), static_cast<WEI_Object>(arg2), static_cast<WEI_Object>(arg3), static_cast<WEI_Object>(arg4));
    }
  }
}

__ATTR_EXPORT_NAME("_exit_kernel") __ATTR_USED
void _exit_kernel(void)
{
  // TODO: call destructor of array
  WebMemoryAllocExit();
}
