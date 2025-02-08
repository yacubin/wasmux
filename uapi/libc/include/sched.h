/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SCHED_H
#define _SCHED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <wasmux/types.h>
#include <wasmux/sched.h>

#define CPU_SETSIZE 1024

struct __cpu_set_struct {
  unsigned long __bits[CPU_SETSIZE / (8 * sizeof(long))];
};

typedef struct __cpu_set_struct cpu_set_t;

#define CPU_COUNT(set)                        \
  {                                           \
    size_t i, j;                              \
    int ret = 0;                              \
    for (i = 0; i < sizeof(set->__bits); i++) \
      for (j = 0; j < 8; j++)                 \
        if (set->__bits[i] & (1 << j))        \
          ret++;                              \
    ret;                                      \
  }

int sched_get_priority_max(int policy);
int sched_get_priority_min(int policy);
int sched_yield(void);
int sched_setscheduler(pid_t tid, int policy, const struct sched_param* param);

int sched_getaffinity(pid_t tid, size_t size, cpu_set_t* set);

#ifdef __cplusplus
}
#endif

#endif /* _SCHED_H */
