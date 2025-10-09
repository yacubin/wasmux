/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_MAINLOOP_H
#define _WASMUX_MAINLOOP_H

#include <wasmux/wei.h>

#ifdef __cplusplus
extern "C" {
#endif

#define LP_ASYNC 0
#define LP_SYNC 1

int WebMainLoopDispatch(WEI_PerformCallback* dispatchCallback, void* userdata, unsigned flags);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_MAINLOOP_H */
