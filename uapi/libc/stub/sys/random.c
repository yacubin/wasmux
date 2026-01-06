/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/random.h>
#include <assert.h>
#include <errno.h>

ssize_t getrandom(void* data, size_t size, unsigned int flags)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
