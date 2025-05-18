/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_TIME_H
#define _WASMUX_TIME_H

#include <wasmux/types.h>

#define CLOCK_REALTIME         0
#define CLOCK_MONOTONIC        1
#define CLOCK_MONOTONIC_COARSE 6
#define CLOCK_BOOTTIME         7

#define TIMER_ABSTIME 1

typedef long suseconds_t;
typedef int32_t time32_t;
typedef int64_t time_t;

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

struct timeval {
  time_t tv_sec;
  suseconds_t tv_usec;
};

struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

#endif /* _WASMUX_TIME_H */
