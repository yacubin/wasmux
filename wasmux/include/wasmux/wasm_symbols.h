/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WASM_SYMBOLS_H
#define _WASMUX_WASM_SYMBOLS_H

#ifdef __cplusplus
extern "C" {
#endif

extern char __global_base;
extern char __data_end;
extern char __stack_low;
extern char __stack_high;
extern char __heap_base;
extern char __heap_end;
extern char __memory_base;
extern char __table_base;

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WASM_SYMBOLS_H */
