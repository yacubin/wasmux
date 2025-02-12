/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <ftw.h>
#include <assert.h>

int nftw(const char* dir, int (*func)(const char*, const struct stat*, int, struct FTW *), int descriptors, int flags)
{
  assert(0);
  return -1;
}
