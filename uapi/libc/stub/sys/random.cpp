/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/random.h"

#include <kernel/assert.h>
#include <errno.h>

ssize_t getrandom(void* data, size_t size, unsigned int flags)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
