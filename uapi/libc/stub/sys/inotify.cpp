/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/inotify.h>
#include <assert.h>
#include <errno.h>

int inotify_init1(int flags)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}

int inotify_add_watch(int fd, const char* name, unsigned mask)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}

int inotify_rm_watch(int fd, int wd)
{
  assert(0);
  __set_local_errno(ENOSYS);
  return -1;
}
