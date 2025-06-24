/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_OBJECT_H
#define _WASMUX_WEB_OBJECT_H

#include <wasmux/wei.h>
#include <wasmux/web/string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebObject WebObject;

WEI_Object WebObject_create();

WEI_Object WebObject_getProperty(WEI_Object object, const char* name);
int WebObject_setProperty(WEI_Object object, const char* name, WEI_Object value);
int WebObject_setIntegerProperty(WEI_Object object, const char* name, int value);
WEI_Object WebObject_callObjMethod(WEI_Object object, const char* method, WEI_Object arg1, WEI_Object arg2, WEI_Object arg3, WEI_Object arg4);

int WebObject_addEventListener(WEI_Object object, const char* type, WEI_PerformCallback1* callback, void* userdata);
int WebObject_getIntegerProperty(WEI_Object object, const WebString* name);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_OBJECT_H */
