/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_TIME_H
#define _WA_LIBC_TIME_H

#include <kernel/time.h>

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
#define CLOCKS_PER_SEC ((clock_t)1000000)

time_t time(time_t* time);
time_t timegm(struct tm *tm);
clock_t clock(void);
void tzset(void);
size_t strftime(char* buf, size_t n, const char* format, const struct tm* tm);

char* ctime(const time_t* time);
time_t mktime(struct tm* tm);

struct tm* localtime(const time_t* time);
struct tm* localtime_r(const time_t* time, struct tm* buf);

struct tm* gmtime(const time_t* time);
struct tm* gmtime_r(const time_t* time, struct tm* buf);

int timespec_get(struct timespec* ts, int base);
int nanosleep(const struct timespec* duration, struct timespec* remain);

int clock_gettime(clockid_t clock_id, struct timespec* tp);
double difftime(time_t time1, time_t time0);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_TIME_H */
