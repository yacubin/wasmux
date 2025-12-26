/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <time.h>
#include <assert.h>
#include <errno.h>
#include <assert.h>
#include <wasmux/export.h>
#include <wasmux/compiler.h>

__EXPORT int __daylight;
int __daylight = 0;
__EXPORT __ATTR_WEAK_ALIAS(__daylight, daylight);

__EXPORT long __timezone;
long __timezone = 0L;
__EXPORT __ATTR_WEAK_ALIAS(__timezone, timezone);

static char __tzname_GMT[] = "GMT";
__EXPORT char* __tzname[];
char* __tzname[2] =
{
  __tzname_GMT,
  __tzname_GMT,
};
__EXPORT __ATTR_WEAK_ALIAS(__tzname, tzname);

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
  return NULL;
}

time_t mktime(struct tm* tm)
{
  assert(0);
  return 0;
}

struct tm* localtime(const time_t* time)
{
  assert(0);
  return NULL;
}

struct tm* localtime_r(const time_t* time, struct tm* buf)
{
  assert(0);
  return NULL;
}

struct tm* gmtime(const time_t* time)
{
  assert(0);
  return NULL;
}

struct tm* gmtime_r(const time_t* time, struct tm* buf)
{
  assert(0);
  return NULL;
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
