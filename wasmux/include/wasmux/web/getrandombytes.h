/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEB_GETRANDOMBYTES_H
#define _WASMUX_WEB_GETRANDOMBYTES_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t WebGetRandomBytes(void* buf, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEB_GETRANDOMBYTES_H */
