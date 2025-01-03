/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_ERRNO_H
#define _WA_LIBC_ERRNO_H

#include <kernel/errno.h>
#include <kernel/thread_data.h>

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
