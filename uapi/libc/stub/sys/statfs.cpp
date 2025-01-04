/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include <sys/statfs.h>

#include <kernel/assert.h>
#include <kernel/errno.h>
#include <kernel/thread_data.h>

int statfs(const char* path, struct statfs* buf)
{
  WA_UNREACHABLE();
  __set_local_errno(ENOSYS);
  return -1;
}

int fstatfs(int fd, struct statfs* buf)
{
  WA_UNREACHABLE();
  __set_local_errno(ENOSYS);
  return -1;
}
