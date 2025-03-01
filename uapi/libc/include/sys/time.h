/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_TIME_H
#define _SYS_TIME_H

#include <wasmux/time.h>

#ifdef __cplusplus
extern "C" {
#endif

int gettimeofday(struct timeval* tv, struct timezone* tz);
int utimes(const char* filename, const struct timeval times[2]);

#define timersub(a, b, r)                       \
  do {                                          \
    (r)->tv_sec = (a)->tv_sec - (b)->tv_sec;    \
    (r)->tv_usec = (a)->tv_usec - (b)->tv_usec; \
    if ((r)->tv_usec < 0) {                     \
      (r)->tv_usec += 1000000;                  \
      (r)->tv_sec--;                            \
    }                                           \
  } while (0)

#ifdef __cplusplus
}
#endif

#endif /* _SYS_TIME_H */
