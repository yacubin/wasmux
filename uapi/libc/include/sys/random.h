/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_RANDOM_H
#define _WA_LIBC_SYS_RANDOM_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GRND_NONBLOCK 0x00000001U
#define GRND_RANDOM   0x00000002U
#define GRND_INSECURE 0x00000004U

ssize_t getrandom(void* data, size_t size, unsigned int flags);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_RANDOM_H */
