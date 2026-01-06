/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_WORKER_H
#define _WASMUX_WEB_WORKER_H

#include <wasmux/web/string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebWorker WebWorker;

WebWorker* WebWorker_create(const WebString* url, const WebString* name);
WebWorker* WebWorker_create2(const char* url, const char* name);
void WebWorker_finalize(WebWorker*);
int WebWorker_terminate(WebWorker*);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_WORKER_H */
