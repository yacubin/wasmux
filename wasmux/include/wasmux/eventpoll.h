/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_EVENTPOLL_H
#define _WASMUX_EVENTPOLL_H

#include <wasmux/types.h>
#include <wasmux/fcntl.h>

#define EPOLL_CLOEXEC O_CLOEXEC

#define EPOLL_CTL_ADD 1  // Add a file descriptor to the epoll instance
#define EPOLL_CTL_DEL 2  // Remove a file descriptor from the epoll instance
#define EPOLL_CTL_MOD 3  // Modify an existing file descriptor in the epoll instance

#define EPOLLIN    0x00000001U
#define EPOLLPRI   0x00000002U
#define EPOLLOUT   0x00000004U
#define EPOLLERR   0x00000008U
#define EPOLLHUP   0x00000010U
#define EPOLLRDHUP 0x00002000U

#define EPOLLONESHOT (1U << 30)
#define EPOLLET      (1U << 31)

typedef union epoll_data {
  void* ptr;
  int fd;
  uint32_t u32;
  uint64_t u64;
} epoll_data_t;

struct epoll_event {
  unsigned events;
  epoll_data_t data;
};

#endif /* _WASMUX_EVENTPOLL_H */
