/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_XMLHTTPREQUEST_H
#define _WASMUX_WEB_XMLHTTPREQUEST_H

#include <wasmux/types.h>
#include <wasmux/web/object.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebFunction WebFunction;

typedef enum WebXMLHttpRequest_ReadyState {
  WebXMLHttpRequest_ReadyState_UNSENT = 0,
  WebXMLHttpRequest_ReadyState_OPENED = 1,
  WebXMLHttpRequest_ReadyState_HEADERS_RECEIVED = 2,
  WebXMLHttpRequest_ReadyState_LOADING = 3,
  WebXMLHttpRequest_ReadyState_DONE = 4,
} WebXMLHttpRequest_ReadyState;

const char* WebXMLHttpRequest_ReadyState_toCString(WebXMLHttpRequest_ReadyState);

WEI_Object WebXMLHttpRequest_create();
int WebXMLHttpRequest_open(WEI_Object xhr, const char* method, const char* url);
int WebXMLHttpRequest_openGET(WEI_Object xhr, const WebString* url);
int WebXMLHttpRequest_send(WEI_Object xhr, WEI_Object body);
WEI_Object WebXMLHttpRequest_response(WEI_Object xhr);
int WebXMLHttpRequest_setResponseType(WEI_Object xhr, const char* type);
int WebXMLHttpRequest_readyState(WEI_Object xhr);
int WebXMLHttpRequest_addOnReadyStateChange(WEI_Object xhr, WEI_PerformCallback1* callback, void* userdata);
WebFunction* WebXMLHttpRequest_addOnLoad(WEI_Object xhr, WEI_PerformCallback1* callback, void* userdata);
int WebXMLHttpRequest_removeOnLoad(WEI_Object xhr, WebFunction* listener);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_XMLHTTPREQUEST_H */
