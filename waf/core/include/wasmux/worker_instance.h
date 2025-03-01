/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WORKER_INSTANCE_H
#define _WASMUX_WORKER_INSTANCE_H

#include <wasmux/types.h>
#include <wasmux/wei.h>
#include <wasmux/web/arraybuffer.h>
#include <wasmux/worker_thread.h>

#ifdef __cplusplus
extern "C" {
#endif

void WebWorkerInstance_init(struct WebWorkerInstance*, const char* name);
struct WebWorkerInstance* WebWorkerInstance_create(const char* name);
int WebWorkerInstance_run(struct WebWorkerInstance*);
int WebWorkerInstance_startModule(struct WebWorkerInstance*, WEI_Object module, struct wasm_memory_info* meminfo);
int WebWorkerInstance_startThread(struct WebWorkerInstance*, WEI_PerformCallback* callback, void* userdata);
int WebWorkerInstance_startBinarySync(struct WebWorkerInstance*, WebArrayBuffer* buffer, struct wasm_memory_info* meminfo);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WORKER_INSTANCE_H */
