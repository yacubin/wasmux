/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/random.h>
#include <wasmux/assert.h>
#include <errno.h>

ssize_t getrandom(void* data, size_t size, unsigned int flags)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
