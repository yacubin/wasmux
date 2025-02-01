/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/stat.h>

int futimens(int fd, const struct timespec times[2])
{
  return utimensat(fd, nullptr, times, 0);
}
