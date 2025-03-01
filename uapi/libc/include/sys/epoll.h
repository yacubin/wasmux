/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_EPOLL_H
#define _SYS_EPOLL_H

#include <wasmux/eventpoll.h>

#ifdef __cplusplus
extern "C" {
#endif

int epoll_create1(int flags);
int epoll_ctl(int epfd, int op, int fd, struct epoll_event* event);
int epoll_wait(int epfd, struct epoll_event* events, int maxevents, int timeout);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_EPOLL_H */
