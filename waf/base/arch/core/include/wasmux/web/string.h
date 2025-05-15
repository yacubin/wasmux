/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_STRING_H
#define _WASMUX_WEB_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebString WebString;

WebString* WebString_create(const char* str);
WebString* WebString_create2(const char* str, unsigned len);
void WebString_destroy(WebString*);
WebString* WebString_clone(WebString*);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_STRING_H */
