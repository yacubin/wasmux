/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <unistd.h>
#include <time.h>

int usleep(useconds_t usec)
{
  const struct timespec ts = {
    .tv_sec  = (static_cast<long>(usec) / 1000000),
    .tv_nsec = (static_cast<long>(usec) % 1000000) * 1000,
  };
  return nanosleep(&ts, nullptr);
}
