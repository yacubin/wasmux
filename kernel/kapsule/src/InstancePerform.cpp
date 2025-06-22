/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/memory_alloc.h>
#include <wasmux/assert.h>

__ATTR_EXPORT_NAME("perform") __ATTR_USED
void _perform_kernel(long number, long callbackAddr, long userdataAddr, long arg1, long arg2, long arg3, long arg4)
{
  switch (number) {
  case 2: { // __WEB_NR_KernelPerform2
    auto userdata = reinterpret_cast<void*>(userdataAddr);
    auto callback = reinterpret_cast<WEI_PerformCallback*>(callbackAddr);
    callback(userdata);
    break;
  }
  case 3: { // __WEB_NR_KernelPerform3
    auto userdata = reinterpret_cast<void*>(userdataAddr);
    auto callback = reinterpret_cast<WEI_PerformCallback1*>(callbackAddr);
    callback(userdata, static_cast<WEI_Object>(arg1));
    break;
  }
  case 4: { // __WEB_NR_KernelPerform4
    auto userdata = reinterpret_cast<void*>(userdataAddr);
    auto callback = reinterpret_cast<WEI_PerformCallback2*>(callbackAddr);
    callback(userdata, static_cast<WEI_Object>(arg1), static_cast<WEI_Object>(arg2));
    break;
  }
  case 5: { // __WEB_NR_KernelPerform5
    auto userdata = reinterpret_cast<void*>(userdataAddr);
    auto callback = reinterpret_cast<WEI_PerformCallback3*>(callbackAddr);
    callback(userdata, static_cast<WEI_Object>(arg1), static_cast<WEI_Object>(arg2), static_cast<WEI_Object>(arg3));
    break;
  }
  case 6: { // __WEB_NR_KernelPerform6
    auto userdata = reinterpret_cast<void*>(userdataAddr);
    auto callback = reinterpret_cast<WEI_PerformCallback4*>(callbackAddr);
    callback(userdata, static_cast<WEI_Object>(arg1), static_cast<WEI_Object>(arg2), static_cast<WEI_Object>(arg3), static_cast<WEI_Object>(arg4));
    break;
  }
  default:
    WA_UNREACHABLE();
    break;
  }
}

__ATTR_EXPORT_NAME("_exit_kernel") __ATTR_USED
void _exit_kernel(void)
{
  // TODO: call destructor of array
  WebMemoryAllocExit();
}
