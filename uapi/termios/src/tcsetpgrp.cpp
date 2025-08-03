/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

__ATTR_HIDDEN
extern "C" pid_t __tcsetpgrp(int fd, pid_t pidgrp)
{
  abort();
  errno = ENOSYS;
  return -1;
}

extern "C" __ATTR_ALIAS(__tcsetpgrp, tcsetpgrp) __ATTR_WEAK;
