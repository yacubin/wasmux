/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_ERRNO_H
#define _WA_LIBC_ERRNO_H

#include <wasmux/errno.h>
#include <wasmux/thread_data.h>

#ifdef __cplusplus
extern "C" {
#endif

#define errno __get_local_errno()

extern char* program_invocation_name;
extern char* program_invocation_short_name;

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_ERRNO_H */
