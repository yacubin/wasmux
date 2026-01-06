/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stddef.h>
#include <sys/stat.h>

int futimens(int fd, const struct timespec times[2])
{
  return utimensat(fd, NULL, times, 0);
}
