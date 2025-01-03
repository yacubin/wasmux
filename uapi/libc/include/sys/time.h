/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_TIME_H
#define _WA_LIBC_SYS_TIME_H

#include <kernel/time.h>

#ifdef __cplusplus
extern "C" {
#endif

int gettimeofday(struct timeval* tv, struct timezone* tz);
int utimes(const char* filename, const struct timeval times[2]);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_TIME_H */
