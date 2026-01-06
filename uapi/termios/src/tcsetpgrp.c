/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include <wasmux/export.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN __EXPORT
pid_t __tcsetpgrp(int fd, pid_t pidgrp)
{
  abort();
  errno = ENOSYS;
  return -1;
}

__EXPORT __ATTR_ALIAS(__tcsetpgrp, tcsetpgrp) __ATTR_WEAK;
