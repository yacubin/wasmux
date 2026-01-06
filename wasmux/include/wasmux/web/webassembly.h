/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_WEBASSEMBLY_H
#define _WASMUX_WEB_WEBASSEMBLY_H

#include <wasmux/wei.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebAssemblyModule WebAssemblyModule;
typedef struct WebAssemblyMemory WebAssemblyMemory;

WEI_Object WebAssembly_compile(WEI_Object buffer);

WebAssemblyMemory* WebAssemblyMemory_create(unsigned initial, unsigned maximum, bool shared);
void WebAssemblyMemory_finalize(WebAssemblyMemory*);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_WEBASSEMBLY_H */
