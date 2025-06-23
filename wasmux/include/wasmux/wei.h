/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEI_H
#define _WASMUX_WEI_H

#include <wasmux/compiler.h>
#include <wasmux/wainst_names.h>

#ifdef __cplusplus
extern "C" {
#endif

__ATTR_IMPORT_NAME(WASMUX_BROWSER_MODULE, WASMUX_BROWSER_MATH_RANDOM)
double WEI_mathRandom();

__ATTR_IMPORT_NAME(WASMUX_BROWSER_MODULE, WASMUX_BROWSER_DATE_NOW)
double WEI_dateNow();

__ATTR_IMPORT_NAME(WASMUX_BROWSER_MODULE, WASMUX_BROWSER_PERFORMANCE_NOW)
double WEI_performanceNow();

__ATTR_IMPORT_NAME(WASMUX_BROWSER_MODULE, WASMUX_BROWSER_WEBCALL)
int WEI_webcall(unsigned number, unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4, unsigned arg5, unsigned arg6);

typedef unsigned WEI_Object;

#define WEI_UNDEFINED_OBJECT ((WEI_Object)0)
#define WEI_KERNEL_MEMORY_ID ((WEI_Object)1)
#define WEI_KERNEL_MODULE_ID ((WEI_Object)2)
#define WEI_USER_WORKER      ((WEI_Object)5)
#define WEI_FALSE_BOOLEAN_ID ((WEI_Object)6)
#define WEI_TRUE_BOOLEAN_ID  ((WEI_Object)7)
#define WEI_NULL_OBJECT      ((WEI_Object)8)
#define WEI_GLOBAL_THIS      ((WEI_Object)9)
#define WEI_SCRIPT_URL_ID    ((WEI_Object)10)

// MAYBE: DispatchCallback
typedef void (WEI_PerformCallback)  (void* userdata);
typedef void (WEI_PerformCallback1) (void* userdata, WEI_Object arg1);
typedef void (WEI_PerformCallback2) (void* userdata, WEI_Object arg1, WEI_Object arg2);
typedef void (WEI_PerformCallback3) (void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3);
typedef void (WEI_PerformCallback4) (void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4);

#define WEI_WEBCALL_NARGS 6

typedef int WEI_CallFunction(unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4, unsigned arg5, unsigned arg6);

WEI_Object WEI_objectCreate(WEI_Object cls);
WEI_Object WEI_objectCreate1(WEI_Object cls, WEI_Object arg1);
WEI_Object WEI_objectCreate2(WEI_Object cls, WEI_Object arg1, WEI_Object arg2);
WEI_Object WEI_objectCreate3(WEI_Object cls, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3);
WEI_Object WEI_objectCreate4(WEI_Object cls, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4);
WEI_Object WEI_objectCreate5(WEI_Object cls, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4, WEI_Object arg5);
WEI_Object WEI_objectRetain(WEI_Object thisObject);
int WEI_objectRelease(WEI_Object thisObject);
WEI_Object WEI_getObjectProperty(WEI_Object thisObject, WEI_Object name);
int WEI_getIntegerProperty(WEI_Object thisObject, WEI_Object name);
int WEI_setObjectProperty(WEI_Object thisObject, WEI_Object name, WEI_Object value);
int WEI_setIntegerProperty(WEI_Object thisObject, WEI_Object name, int value);
WEI_Object WEI_callObjectMethod(WEI_Object thisObject, WEI_Object name);
WEI_Object WEI_callObjectMethod1(WEI_Object thisObject, WEI_Object name, WEI_Object arg1);
WEI_Object WEI_callObjectMethod2(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2);
WEI_Object WEI_callObjectMethod3(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3);
WEI_Object WEI_callObjectMethod4(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4);
int WEI_callIntegerMethod(WEI_Object thisObject, WEI_Object name);
int WEI_callIntegerMethod1(WEI_Object thisObject, WEI_Object name, WEI_Object arg1);
int WEI_callIntegerMethod2(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2);
int WEI_callIntegerMethod3(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3);
int WEI_callIntegerMethod4(WEI_Object thisObject, WEI_Object name, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4);
WEI_Object WEI_addEventListener(WEI_Object thisObject, WEI_Object type, WEI_PerformCallback1* callback, void* userdata);
int WEI_removeEventListener(WEI_Object thisObject, WEI_Object type, WEI_Object listener);
int WEI_promiseThen(WEI_Object thisObject, WEI_PerformCallback1* resolveCallback, WEI_PerformCallback1* rejectCallback, void* userdata);
int WEI_postMessage(WEI_PerformCallback* callback, void* userdata);
int WEI_postMessage1(WEI_PerformCallback1* callback, void* userdata, WEI_Object arg1);
int WEI_postMessage2(WEI_PerformCallback2* callback, void* userdata, WEI_Object arg1, WEI_Object arg2);
int WEI_postMessage3(WEI_PerformCallback3* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3);
int WEI_postMessage4(WEI_PerformCallback4* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4);
unsigned WEI_setTimeout(WEI_PerformCallback* callback, void* userdata, int delayMs);
unsigned WEI_setInterval(WEI_PerformCallback* callback, void* userdata, int delayMs);
void WEI_clearTimeout(unsigned timeoutID);
void WEI_clearInterval(unsigned intervalID);
int WEI_workerPerform(WEI_Object thisObject, WEI_PerformCallback* callback, void* userdata);
int WEI_workerPerform1(WEI_Object thisObject, WEI_PerformCallback1* callback, void* userdata, WEI_Object arg1);
int WEI_workerPerform2(WEI_Object thisObject, WEI_PerformCallback2* callback, void* userdata, WEI_Object arg1, WEI_Object arg2);
int WEI_workerPerform3(WEI_Object thisObject, WEI_PerformCallback3* callback, void* userdata, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3);
int WEI_workerInstance(WEI_Object thisObject);
WEI_Object WEI_stringCreate(WEI_Object memory, const char* str, unsigned len);
WEI_Object WEI_stringCreateByArgs(unsigned arg1, unsigned arg2, unsigned arg3, unsigned arg4, unsigned arg5, unsigned arg6);
WEI_Object WEI_numberCreate(int value);
int WEI_consoleWrite(int level, WEI_Object message);
WEI_Object WEI_memoryCreate(unsigned initial, unsigned maximum, bool shared);
unsigned WEI_memoryCopy(WEI_Object dstMemory, void* dstData, WEI_Object srcMemory, const void* srcData, unsigned size);
unsigned WEI_memorySize(WEI_Object memory);
unsigned WEI_memoryGrow(WEI_Object memory, unsigned delta);
unsigned WEI_memoryStrnlen(WEI_Object memory, const char* str, long n);
unsigned WEI_memoryStrncpy(WEI_Object dstMemory, char* dst, WEI_Object srcMemory, const char* src, unsigned count);
unsigned WEI_memoryFill(WEI_Object memory, void* ptr, int val, unsigned len);
int WEI_userInstanceStart(WEI_Object module, WEI_Object memory);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEI_H */
