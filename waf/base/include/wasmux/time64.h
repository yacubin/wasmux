/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_TIME64_H
#define _WASMUX_TIME64_H

#include <wasmux/types.h>

typedef int64_t time64_t;

struct timespec64 {
  time64_t tv_sec;
  long tv_nsec;
};

#endif /* _WASMUX_TIME64_H */
