/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sched.h>
#include <assert.h>

int sched_setscheduler(pid_t tid, int policy, const struct sched_param* param)
{
  assert(0);
  return 0;
}
