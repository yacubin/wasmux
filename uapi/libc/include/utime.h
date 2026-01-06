/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _UTIME_H
#define _UTIME_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct utimbuf {
  time_t actime;
  time_t modtime;
};

int utime(const char* filename, const struct utimbuf* times);

#ifdef __cplusplus
}
#endif

#endif /* _UTIME_H */
