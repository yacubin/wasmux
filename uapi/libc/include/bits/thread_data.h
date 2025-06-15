/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_THREAD_DATA_H
#define _BITS_THREAD_DATA_H

#include <wasmux/thread_data.h>

#ifdef __cplusplus
extern "C" {
#endif

struct wax_thread_data* __get_thread_data();

#define __get_local_errno() __get_thread_data()->errcode
#define __set_local_errno(code) __get_thread_data()->errcode = code
#define __get_local_buffer_data() __get_thread_data()->buffer
#define __get_local_buffer_size() sizeof(__get_thread_data()->buffer)

#ifdef __cplusplus
}
#endif

#endif /* _BITS_THREAD_DATA_H */
