/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "poll.h"

#include <kernel/assert.h>
#include <errno.h>

int poll(struct pollfd* fds, nfds_t nfds, int timeout)
{
  errno = ENOSYS;
  WA_UNREACHABLE();
  return -1;
}
