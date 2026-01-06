/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _POLL_H
#define _POLL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long nfds_t;

struct pollfd {
  int fd;
  short events;
  short revents;
};

#define POLLIN     0x0001  /* Data to read */
#define POLLPRI    0x0002  /* Urgent data */
#define POLLOUT    0x0004  /* Ready for writing */
#define POLLERR    0x0008  /* Error occurred */
#define POLLHUP    0x0010  /* Hang-up detected */
#define POLLNVAL   0x0020  /* Invalid file descriptor */

#define POLLRDNORM 0x0040  /* Normal data to read */
#define POLLRDBAND 0x0080  /* Priority band data to read */
#define POLLWRNORM 0x0100  /* Writing now will not block */
#define POLLWRBAND 0x0200  /* Priority band data can be written */

int poll(struct pollfd* fds, nfds_t nfds, int timeout);

#ifdef __cplusplus
}
#endif

#endif /* _POLL_H */
