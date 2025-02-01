/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SCHED_H
#define _SCHED_H

#include <wasmux/types.h>
#include <wasmux/sched.h>

int sched_yield(void);
int sched_setscheduler(pid_t tid, int policy, const struct sched_param* param);

#endif /* _SCHED_H */
