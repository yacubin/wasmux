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
#include <wasmux/cpu_set.h>

#define CPU_SETSIZE __CPU_SETSIZE

static inline int __sched_cpu_count(const cpu_set_t* cpuset)
{
  size_t i, j;

  int ret = 0;
  for (i = 0; i < sizeof(cpuset->__bits); i++) {
    for (j = 0; j < 8; j++) {
      if (cpuset->__bits[i] & (1 << j))
        ret++;
    }
  }

  return ret;
}

#define __CPU_op_S(index, size, cpuset, op) \
  ({ \
    ((index) / 8UL < (size)) ? ((cpuset)->__bits[(index) / 8 / sizeof(__cpu_mask)] op (1UL << ((index) % (8 * sizeof(__cpu_mask))))) : 0; \
  })

#define CPU_COUNT(cpuset) __sched_cpu_count(cpuset)

#define CPU_ZERO_S(size, cpuset) __builtin_memset(cpuset, 0, size)
#define CPU_SET_S(index, size, cpuset) __CPU_op_S(index, size, cpuset, |=)
#define CPU_ISSET_S(index, size, cpuset) __CPU_op_S(index, size, cpuset, &)

#define CPU_ZERO(cpuset) CPU_ZERO_S(sizeof(cpu_set_t), cpuset)
#define CPU_SET(index, cpuset) CPU_SET_S(index, sizeof(cpu_set_t), cpuset)
#define CPU_ISSET(index, cpuset) CPU_ISSET_S(index, sizeof(cpu_set_t), cpuset)

int sched_get_priority_max(int policy);
int sched_get_priority_min(int policy);
int sched_yield(void);
int sched_setscheduler(pid_t tid, int policy, const struct sched_param* param);

int sched_getcpu(void);
int sched_getaffinity(pid_t tid, size_t size, cpu_set_t* set);

#ifdef __cplusplus
}
#endif

#endif /* _SCHED_H */
