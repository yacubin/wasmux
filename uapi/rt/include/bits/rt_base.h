/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_RT_BASE_H
#define _BITS_RT_BASE_H

#include <wasmux/time.h>

#ifdef __cplusplus
extern "C" {
#endif

int clock_gettime(clockid_t clock_id, struct timespec* ts);
int clock_getres(clockid_t clock_id, struct timespec* ts);
int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec* req, struct timespec* rem);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_RT_BASE_H */
