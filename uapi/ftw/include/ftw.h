/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _FTW_H
#define _FTW_H

#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FTW_F 1
#define FTW_DEPTH 8

#define FTW_PHYS 1

struct FTW {
  int base;
  int level;
};

int ftw(const char* dir, int (*func)(const char*, const struct stat*, int), int descriptors);
int nftw(const char* dir, int (*func)(const char*, const struct stat*, int, struct FTW*), int descriptors, int flags);

#ifdef __cplusplus
}
#endif

#endif /* _FTW_H */
