/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_SELECT_H
#define _SYS_SELECT_H

#include <wasmux/types.h>
#include <wasmux/posix_types.h>
#include <wasmux/time.h>
#include <wasmux/signal.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FD_CLR(fd, set) ((void)0)
#define FD_SET(fd, set) ((void)0)
#define FD_ISSET(fd, set) (0)
#define FD_ZERO(set) ((void)0)

int select(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, struct timeval* timeout);
int pselect(int nfds, fd_set* readfds, fd_set* writefds, fd_set* exceptfds, const struct timespec* timeout, const sigset_t* sigmask);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SELECT_H */
