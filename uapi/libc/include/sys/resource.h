/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_RESOURCE_H
#define _WA_LIBC_SYS_RESOURCE_H

#include <kernel/time.h>
#include <sys/types.h> // for id_t

#ifdef __cplusplus
extern "C" {
#endif

#define RLIMIT_DATA   2
#define RLIMIT_STACK  3
#define RLIMIT_NOFILE 7

#define RLIM_INFINITY (~0UL)

#define RLIM_SAVED_MAX RLIM_INFINITY
#define RLIM_SAVED_CUR RLIM_INFINITY

typedef unsigned long rlim_t;

struct rlimit {
  rlim_t rlim_cur;
  rlim_t rlim_max;
};

int getrlimit(int resource, struct rlimit* rlim);
int setrlimit(int resource, const struct rlimit* rlim);

#define RUSAGE_SELF     (0)
#define RUSAGE_CHILDREN (-1)
#define RUSAGE_BOTH     (-2)
#define RUSAGE_THREAD   (1)

struct rusage {
  struct timeval ru_utime;
  struct timeval ru_stime;
  long ru_maxrss;
  long ru_ixrss;
  long ru_idrss;
  long ru_isrss;
  long ru_minflt;
  long ru_majflt;
  long ru_nswap;
  long ru_inblock;
  long ru_oublock;
  long ru_msgsnd;
  long ru_msgrcv;
  long ru_nsignals;
  long ru_nvcsw;
  long ru_nivcsw;
};

int getrusage(int who, struct rusage* usage);

#define PRIO_PROCESS 0
#define PRIO_PGRP    1
#define PRIO_USER    2

int getpriority(int which, id_t who);
int setpriority(int which, id_t who, int value);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_RESOURCE_H */
