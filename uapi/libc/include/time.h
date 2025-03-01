/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _TIME_H
#define _TIME_H

#include <wasmux/time.h>
#include <wasmux/time64.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TIME_UTC 1

struct tm {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

typedef long clock_t;
typedef int clockid_t;
#define CLOCKS_PER_SEC ((clock_t)1000000)

extern char* tzname[2];
extern int daylight;
extern long timezone;

time_t time(time_t* time);
time_t timegm(struct tm *tm);
clock_t clock(void);
void tzset(void);
size_t strftime(char* buf, size_t n, const char* format, const struct tm* tm);

char* ctime(const time_t* time);
char* ctime_r(const time_t* time, char* buf);
time_t mktime(struct tm* tm);

struct tm* localtime(const time_t* time);
struct tm* localtime_r(const time_t* time, struct tm* buf);

struct tm* gmtime(const time_t* time);
struct tm* gmtime_r(const time_t* time, struct tm* buf);

int timespec_get(struct timespec* ts, int base);
int nanosleep(const struct timespec* duration, struct timespec* remain);

double difftime(time_t time1, time_t time0);

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};

int clock_gettime(clockid_t clock_id, struct timespec* ts);
int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec* req, struct timespec* rem);

#ifdef __cplusplus
}
#endif

#endif /* _TIME_H */
