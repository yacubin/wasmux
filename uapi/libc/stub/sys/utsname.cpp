/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "sys/utsname.h"

#include <wasmux/assert.h>
#include <errno.h>

int uname(struct utsname* buf)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
