/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_TIME_H
#define _WA_KERNEL_TIME_H

#include <wasmux/types.h>

#define CLOCK_REALTIME  0
#define CLOCK_MONOTONIC 1
#define CLOCK_BOOTTIME  7

typedef long suseconds_t;
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

#endif /* _WA_KERNEL_TIME_H */
