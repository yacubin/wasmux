/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_TIMERFD_H
#define _SYS_TIMERFD_H

#include <wasmux/timerfd.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

int timerfd_create(int clock_id, int flags);
int timerfd_gettime(int fd, struct itimerspec* cur_its);
int timerfd_settime(int ufd, int flags, const struct itimerspec* new_its, struct itimerspec* old_its);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_TIMERFD_H */
