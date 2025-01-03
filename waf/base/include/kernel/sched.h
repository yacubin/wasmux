/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_SCHED_H
#define _WA_KERNEL_SCHED_H

#define SCHED_NORMAL 0
#define SCHED_FIFO   1
#define SCHED_RR     2
#define SCHED_BATCH  3

#define SCHED_OTHER SCHED_NORMAL

struct sched_param {
  int sched_priority;
};

#endif /* _WA_KERNEL_SCHED_H */
