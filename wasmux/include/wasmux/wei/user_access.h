/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_WEI_USERACCESS_H
#define _WASMUX_WEI_USERACCESS_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

unsigned long WebCopyFromUserMemory(void* to, const void* from, unsigned long n);
unsigned long WebCopyToUserMemory(void* to, const void* from, unsigned long n);
long WebStrncpyFromUser(char* dst, const char* src, long count);
long WebStrnlenUserMemory(const char* str, long n);
unsigned long WebClearUserMemory(void* mem, unsigned long len);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_WEI_USERACCESS_H */
