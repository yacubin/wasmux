/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_WORKER_H
#define _WASMUX_WEB_WORKER_H

#include <wasmux/types.h>
#include <wasmux/web/object.h>

#ifdef __cplusplus
extern "C" {
#endif

WEI_Object WebWorker_create(WEI_Object url, WEI_Object name);
WEI_Object WebWorker_create2(const char* url, const char* name);
int WebWorker_terminate(WEI_Object worker);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_WORKER_H */
