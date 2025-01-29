/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

__ATTR_HIDDEN
extern "C" int __fstatat(int dirfd, const char* path, struct stat* buf, int flags)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return 0;
}

extern "C" __ATTR_ALIAS(__fstatat, fstatat) __ATTR_WEAK;
