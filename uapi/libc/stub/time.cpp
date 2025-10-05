/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <assert.h>
#include <wasmux/compiler.h>

extern "C" int __daylight;
int __daylight = 0;
extern "C" __ATTR_ALIAS(__daylight, daylight) __ATTR_WEAK;

extern "C" long __timezone;
long __timezone = 0L;
extern "C" __ATTR_ALIAS(__timezone, timezone) __ATTR_WEAK;

static char __tzname_GMT[] = "GMT";
extern "C" char* __tzname[];
char* __tzname[2] =
{
  __tzname_GMT,
  __tzname_GMT,
};
extern "C" __ATTR_ALIAS(__tzname, tzname) __ATTR_WEAK;

time_t time(time_t* time)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

time_t timegm(struct tm *tm)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

clock_t clock(void)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void tzset(void)
{
  assert(0);
}

size_t strftime(char* buf, size_t n, const char* format, const struct tm* tm)
{
  assert(0);
  return 0;
}

char* ctime(const time_t* time)
{
  return ctime_r(time, __get_local_buffer_data());
}

char* ctime_r(const time_t* time, char* buf)
{
  assert(0);
  return nullptr;
}

time_t mktime(struct tm* tm)
{
  assert(0);
  return 0;
}

struct tm* localtime(const time_t* time)
{
  assert(0);
  return nullptr;
}

struct tm* localtime_r(const time_t* time, struct tm* buf)
{
  assert(0);
  return nullptr;
}

struct tm* gmtime(const time_t* time)
{
  assert(0);
  return nullptr;
}

struct tm* gmtime_r(const time_t* time, struct tm* buf)
{
  assert(0);
  return nullptr;
}

int nanosleep(const struct timespec* duration, struct timespec* remain)
{
  assert(0);
  return -1;
}

double difftime(time_t time1, time_t time0)
{
  assert(0);
  errno = ENOSYS;
  return 0.0;
}
