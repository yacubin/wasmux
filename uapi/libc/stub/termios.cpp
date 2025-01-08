/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "termios.h"

#include <wasmux/assert.h>
#include <sys/ioctl.h> // for tcgetattr
#include <errno.h>

int tcflow(int fd, int action)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int tcgetattr(int fd, struct termios* termios)
{
  if (nullptr == termios) {
    __set_local_errno(EINVAL);
    return -1;
  }

  return ioctl(fd, TCGETS, termios);
}

int tcsetattr(int fd, int optional_actions, const struct termios* termios)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int tcflush(int fd, int queue_selector)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

speed_t cfgetispeed(const struct termios* termios)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

speed_t cfgetospeed(const struct termios* termios)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int cfsetispeed(struct termios* termios, speed_t speed)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int cfsetospeed(struct termios* termios, speed_t speed)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
