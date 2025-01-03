/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_POLL_H
#define _WA_LIBC_POLL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long nfds_t;

struct pollfd {
  int fd;
  short events;
  short revents;
};

#define POLLIN    0x00000001  // Data to read
#define POLLPRI   0x00000002  // Urgent data
#define POLLOUT   0x00000004  // Ready for writing
#define POLLERR   0x00000008  // Error occurred
#define POLLHUP   0x00000010  // Hang-up detected
#define POLLNVAL  0x00000020  // Invalid file descriptor

int poll(struct pollfd* fds, nfds_t nfds, int timeout);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_POLL_H */
