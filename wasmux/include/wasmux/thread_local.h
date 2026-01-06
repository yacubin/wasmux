/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_THREAD_LOCAL_H
#define _WASMUX_THREAD_LOCAL_H

#if defined(__cplusplus)
# define __THREAD_LOCAL thread_local
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
# define __THREAD_LOCAL _Thread_local
#elif defined(_MSC_VER)
# define __THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__) || defined(__clang__)
# define __THREAD_LOCAL __thread
#else
# error "No thread-local storage support"
#endif

#endif /* _WASMUX_THREAD_LOCAL_H */
