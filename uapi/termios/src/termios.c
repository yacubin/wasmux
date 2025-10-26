/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <termios.h>
#include <sys/ioctl.h> // for tcgetattr
#include <errno.h>
#include <assert.h>

pid_t tcgetsid(int fd)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int tcdrain(int fd)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int tcflow(int fd, int action)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int tcgetattr(int fd, struct termios* termios)
{
  if (NULL == termios) {
    __set_local_errno(EINVAL);
    return -1;
  }

  return ioctl(fd, TCGETS, termios);
}

int tcsetattr(int fd, int optional_actions, const struct termios* termios)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int tcflush(int fd, int queue_selector)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

speed_t cfgetispeed(const struct termios* termios)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

speed_t cfgetospeed(const struct termios* termios)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int cfsetispeed(struct termios* termios, speed_t speed)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int cfsetospeed(struct termios* termios, speed_t speed)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void cfmakeraw(struct termios* termios)
{
  assert(0);
}
