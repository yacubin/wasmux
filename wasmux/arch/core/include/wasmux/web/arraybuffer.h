/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_ARRAYBUFFER_H
#define _WASMUX_WEB_ARRAYBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebArrayBuffer WebArrayBuffer;

WebArrayBuffer* WebArrayBuffer_create(unsigned size, bool shared);
void WebArrayBuffer_destroy(WebArrayBuffer*);
unsigned WebArrayBuffer_byteLength(const WebArrayBuffer*);
WebArrayBuffer* WebArrayBuffer_clone(const WebArrayBuffer*);
unsigned WebArrayBuffer_setBytes(WebArrayBuffer*, unsigned offset, const void* data, unsigned size);

typedef struct Uint8ClampedArray Uint8ClampedArray;
Uint8ClampedArray* WebArrayBuffer_toUint8ClampedArray(WebArrayBuffer*);
void Uint8ClampedArray_destroy(Uint8ClampedArray*);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_ARRAYBUFFER_H */
