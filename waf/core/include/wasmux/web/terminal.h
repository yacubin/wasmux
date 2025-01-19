/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_TERMINAL_H
#define _WASMUX_WEB_TERMINAL_H

#include <wasmux/types.h>
#include <wasmux/wei.h>
#include <wasmux/web/string.h>
#include <wasmux/web/arraybuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebTerminalManager {
  int dummy;
} WebTerminalManager;

typedef struct WebTerminal WebTerminal;

void WebTerminalManager_init(WebTerminalManager*);
void WebTerminalManager_finalize(WebTerminalManager*);

WebTerminal* WebTerminalManager_openSync(WebTerminalManager*, int* errorCode);
int WebTerminalManager_writeSync(WebTerminalManager*, WebTerminal*, WEI_Object mem, const char* buf, unsigned len);
int WebTerminalManager_closeSync(WebTerminalManager*, WebTerminal*);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_TERMINAL_H */
