/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "time.h"

#include <wasmux/assert.h>
#include <errno.h>

time_t time(time_t* time)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

time_t timegm(struct tm *tm)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

clock_t clock(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void tzset(void)
{
  WA_UNREACHABLE();
}

size_t strftime(char* buf, size_t n, const char* format, const struct tm* tm)
{
  WA_UNREACHABLE();
  return 0;
}

char* ctime(const time_t* time)
{
  WA_UNREACHABLE();
  return nullptr;
}

time_t mktime(struct tm* tm)
{
  WA_UNREACHABLE();
  return 0;
}

struct tm* localtime(const time_t* time)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct tm* localtime_r(const time_t* time, struct tm* buf)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct tm* gmtime(const time_t* time)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct tm* gmtime_r(const time_t* time, struct tm* buf)
{
  WA_UNREACHABLE();
  return nullptr;
}

int nanosleep(const struct timespec* duration, struct timespec* remain)
{
  WA_UNREACHABLE();
  return -1;
}

int clock_gettime(clockid_t clock_id, struct timespec* ts)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

double difftime(time_t time1, time_t time0)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return 0.0;
}
