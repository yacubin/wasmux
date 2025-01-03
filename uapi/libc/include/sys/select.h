/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_SELECT_H
#define _WA_LIBC_SYS_SELECT_H

#include <kernel/types.h>
#include <kernel/posix_types.h>
#include <kernel/signal.h>
#include <kernel/time.h>

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

#endif /* _WA_LIBC_SYS_SELECT_H */
