/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_PLATFORM_H
#define _WASMUX_PLATFORM_H

#if defined(__wasm__) || defined(__wasm32__) || defined(__wasm64__)
#define WA_CPU_WASM 1
#endif

#if defined(_WIN32) || defined(WIN32)
# define WA_OS_WINDOWS 1
#endif

#if defined(__linux__) || defined(__linux) || defined(ANDROID) || defined(__ANDROID__)
#define WA_OS_LINUX 1
#endif

#if !(defined(WA_OS_WINDOWS) && defined(WA_OS_LINUX))
# define WA_OS_UNKNOWN 1
#endif

#endif /* _WASMUX_PLATFORM_H */
