/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/statfs.h>

#include <wasmux/assert.h>
#include <wasmux/errno.h>
#include <wasmux/thread_data.h>

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
