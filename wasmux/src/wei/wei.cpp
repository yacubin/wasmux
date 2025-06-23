/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/wei.h>
#include <wasmux/assert.h>
#include <wasmux/limits-base.h>
#include <wasmux/webcall-nums.h>

template<typename T>
inline WEI_Object object_idx_cast(T* ptr)
{
  WA_ASSERT(reinterpret_cast<unsigned long>(ptr) <= UINT_MAX);
  return static_cast<WEI_Object>(reinterpret_cast<unsigned long>(ptr));
}

template<typename T>
inline T* object_ptr_cast(WEI_Object object)
{
  return reinterpret_cast<T*>(object);
}

WEI_Object WEI_objectCreate(WEI_Object cls)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectCreate, static_cast<unsigned>(cls), 0, 0, 0, 0, 0));
}

WEI_Object WEI_objectCreate1(WEI_Object cls, WEI_Object arg1)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectCreate, static_cast<unsigned>(cls), static_cast<unsigned>(arg1), 0, 0, 0, 0));
}

WEI_Object WEI_objectCreate2(WEI_Object cls, WEI_Object arg1, WEI_Object arg2)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectCreate, static_cast<unsigned>(cls), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), 0, 0, 0));
}

WEI_Object WEI_objectCreate3(WEI_Object cls, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectCreate, static_cast<unsigned>(cls), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), 0, 0));
}

WEI_Object WEI_objectCreate4(WEI_Object cls, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectCreate, static_cast<unsigned>(cls), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), static_cast<unsigned>(arg4), 0));
}

WEI_Object WEI_objectCreate5(WEI_Object cls, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4, WEI_Object arg5)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectCreate, static_cast<unsigned>(cls), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), static_cast<unsigned>(arg4), static_cast<unsigned>(arg5)));
}

WEI_Object WEI_objectRetain(WEI_Object thisObject)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_ObjectRetain, static_cast<unsigned>(thisObject), 0, 0, 0, 0, 0));
}

int WEI_objectRelease(WEI_Object thisObject)
{
  return WEI_webcall(__WEB_NR_ObjectRelease, static_cast<unsigned>(thisObject), 0, 0, 0, 0, 0);
}

WEI_Object WEI_getObjectProperty(WEI_Object thisObject, WEI_Object name)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_GetObjectProperty, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), 0, 0, 0, 0));
}

int WEI_getIntegerProperty(WEI_Object thisObject, WEI_Object name)
{
  return WEI_webcall(__WEB_NR_GetIntegerProperty, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), 0, 0, 0, 0);
}

int WEI_setObjectProperty(WEI_Object thisObject, WEI_Object name, WEI_Object value)
{
  return WEI_webcall(__WEB_NR_SetObjectProperty, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(value), 0, 0, 0);
}

int WEI_setIntegerProperty(WEI_Object thisObject, WEI_Object name, int value)
{
  return WEI_webcall(__WEB_NR_SetIntegerProperty, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(value), 0, 0, 0);
}

WEI_Object WEI_callObjectMethod(WEI_Object thisObject, WEI_Object name)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_CallObjectMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), 0, 0, 0, 0));
}

WEI_Object WEI_callObjectMethod1(WEI_Object thisObject, WEI_Object name, WEI_Object arg1)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_CallObjectMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), 0, 0, 0));
}

WEI_Object WEI_callObjectMethod2(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_CallObjectMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), 0, 0));
}

WEI_Object WEI_callObjectMethod3(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_CallObjectMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), 0));
}

WEI_Object WEI_callObjectMethod4(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_CallObjectMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), static_cast<unsigned>(arg4)));
}

int WEI_callIntegerMethod(WEI_Object thisObject, WEI_Object name)
{
  return WEI_webcall(__WEB_NR_CallIntegerMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), 0, 0, 0, 0);
}

int WEI_callIntegerMethod1(WEI_Object thisObject, WEI_Object name, WEI_Object arg1)
{
  return WEI_webcall(__WEB_NR_CallIntegerMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), 0, 0, 0);
}

int WEI_callIntegerMethod2(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2)
{
  return WEI_webcall(__WEB_NR_CallIntegerMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), 0, 0);
}

int WEI_callIntegerMethod3(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return WEI_webcall(__WEB_NR_CallIntegerMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), 0);
}

int WEI_callIntegerMethod4(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  return WEI_webcall(__WEB_NR_CallIntegerMethod, static_cast<unsigned>(thisObject), static_cast<unsigned>(name), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), static_cast<unsigned>(arg4));
}

WEI_Object WEI_addEventListener(WEI_Object thisObject, WEI_Object type, WEI_PerformCallback1* callback, void* userdata)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_AddEventListener, static_cast<unsigned>(thisObject), static_cast<unsigned>(type), object_idx_cast(callback), object_idx_cast(userdata), 0, 0));
}

int WEI_removeEventListener(WEI_Object thisObject, WEI_Object type, WEI_Object listener)
{
  return WEI_webcall(__WEB_NR_RemoveEventListener, static_cast<unsigned>(thisObject), static_cast<unsigned>(type), static_cast<unsigned>(listener), 0, 0, 0);
}

int WEI_promiseThen(WEI_Object thisObject, WEI_PerformCallback1* resolveCallback, WEI_PerformCallback1* rejectCallback, void* userdata)
{
  return WEI_webcall(__WEB_NR_PromiseThen, static_cast<unsigned>(thisObject), object_idx_cast(resolveCallback), object_idx_cast(rejectCallback), object_idx_cast(userdata), 0, 0);
}

int WEI_postMessage(WEI_PerformCallback* callback, void* userdata)
{
  return WEI_webcall(__WEB_NR_PostMessage2, object_idx_cast(callback), object_idx_cast(userdata), 0, 0, 0, 0);
}

int WEI_postMessage1(WEI_PerformCallback1* callback, void* userdata, WEI_Object arg1)
{
  return WEI_webcall(__WEB_NR_PostMessage3, object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), 0, 0, 0);
}

int WEI_postMessage2(WEI_PerformCallback2* callback, void* userdata, WEI_Object arg1, WEI_Object arg2)
{
  return WEI_webcall(__WEB_NR_PostMessage4, object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), 0, 0);
}

int WEI_postMessage3(WEI_PerformCallback3* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return WEI_webcall(__WEB_NR_PostMessage5, object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), 0);
}

int WEI_postMessage4(WEI_PerformCallback4* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4)
{
  return WEI_webcall(__WEB_NR_PostMessage6, object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3), static_cast<unsigned>(arg4));
}

unsigned WEI_setTimeout(WEI_PerformCallback* callback, void* userdata, int delayMs)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_SetTimeout, object_idx_cast(callback), object_idx_cast(userdata), delayMs, 0, 0, 0));
}

unsigned WEI_setInterval(WEI_PerformCallback* callback, void* userdata, int delayMs)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_SetInterval, object_idx_cast(callback), object_idx_cast(userdata), delayMs, 0, 0, 0));
}

void WEI_clearTimeout(unsigned timeoutID)
{
  (void)WEI_webcall(__WEB_NR_ClearTimeout, timeoutID, 0, 0, 0, 0, 0);
}

void WEI_clearInterval(unsigned intervalID)
{
  (void)WEI_webcall(__WEB_NR_ClearInterval, intervalID, 0, 0, 0, 0, 0);
}

int WEI_workerPerform(WEI_Object thisObject, WEI_PerformCallback* callback, void* userdata)
{
  return WEI_webcall(__WEB_NR_WorkerPerform2, static_cast<unsigned>(thisObject), object_idx_cast(callback), object_idx_cast(userdata), 0, 0, 0);
}

int WEI_workerPerform1(WEI_Object thisObject, WEI_PerformCallback1* callback, void* userdata, WEI_Object arg1)
{
  return WEI_webcall(__WEB_NR_WorkerPerform3, static_cast<unsigned>(thisObject), object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), 0, 0);
}

int WEI_workerPerform2(WEI_Object thisObject, WEI_PerformCallback2* callback, void* userdata, WEI_Object arg1, WEI_Object arg2)
{
  return WEI_webcall(__WEB_NR_WorkerPerform4, static_cast<unsigned>(thisObject), object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), 0);
}

int WEI_workerPerform3(WEI_Object thisObject, WEI_PerformCallback3* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3)
{
  return WEI_webcall(__WEB_NR_WorkerPerform5, static_cast<unsigned>(thisObject), object_idx_cast(callback), object_idx_cast(userdata), static_cast<unsigned>(arg1), static_cast<unsigned>(arg2), static_cast<unsigned>(arg3));
}

int WEI_workerInstance(WEI_Object thisObject)
{
  return WEI_webcall(__WEB_NR_WorkerInstance, static_cast<unsigned>(thisObject), 0, 0, 0, 0, 0);
}

WEI_Object WEI_stringCreate(WEI_Object memory, const char* str, unsigned len)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_StringCreate, memory, object_idx_cast(str), len, 0, 0, 0));
}

WEI_Object WEI_stringCreateByArgs(unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4, unsigned arg5, unsigned arg6)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_StringCreateByArgs, arg1, arg2, arg3, arg4, arg5, arg6));
}

WEI_Object WEI_numberCreate(int value)
{
  return static_cast<WEI_Object>(WEI_webcall(__WEB_NR_NumberCreate, value, 0, 0, 0, 0, 0));
}

int WEI_consoleWrite(int level, WEI_Object message)
{
  return WEI_webcall(__WEB_NR_ConsoleWrite, level, static_cast<int>(message), 0, 0, 0, 0);
}

WEI_Object WEI_memoryCreate(unsigned initial, unsigned maximum, bool shared)
{
  return WEI_webcall(__WEB_NR_MemoryCreate, initial, maximum, static_cast<unsigned>(shared), 0, 0, 0);
}

unsigned WEI_memoryCopy(WEI_Object dstMemory, void* dstData, WEI_Object srcMemory, const void* srcData, unsigned size)
{
  return WEI_webcall(__WEB_NR_MemoryCopy, static_cast<unsigned>(dstMemory), object_idx_cast(dstData), static_cast<unsigned>(srcMemory), object_idx_cast(srcData), size, 0);
}

unsigned WEI_memorySize(WEI_Object memory)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_MemorySize, static_cast<unsigned>(memory), 0, 0, 0, 0, 0));
}

unsigned WEI_memoryGrow(WEI_Object memory, unsigned delta)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_MemoryGrow, static_cast<unsigned>(memory), delta, 0, 0, 0, 0));
}

unsigned WEI_memoryStrnlen(WEI_Object memory, const char* str, long n)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_MemoryStrnlen, reinterpret_cast<unsigned>(memory), object_idx_cast(str), 0, 0, 0, 0));
}

unsigned WEI_memoryStrncpy(WEI_Object dstMemory, char* dst, WEI_Object srcMemory, const char* src, unsigned count)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_MemoryStrncpy, dstMemory, object_idx_cast(dst), srcMemory, object_idx_cast(src), count, 0));
}

unsigned WEI_memoryFill(WEI_Object memory, void* ptr, int val, unsigned len)
{
  return static_cast<unsigned>(WEI_webcall(__WEB_NR_MemoryFill, static_cast<long>(memory), object_idx_cast(ptr), static_cast<unsigned>(val), len, 0, 0));
}

int WEI_userInstanceStart(WEI_Object module, WEI_Object memory)
{
  return WEI_webcall(__WEB_NR_UserInstanceStart, static_cast<unsigned>(module), static_cast<unsigned>(memory), 0, 0, 0, 0);
}
