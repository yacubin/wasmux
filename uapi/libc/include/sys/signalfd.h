/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_SIGNALFD_H
#define _SYS_SIGNALFD_H

#include <wasmux/signalfd.h>
#include <bits/signal.h>

#ifdef __cplusplus
extern "C" {
#endif

int signalfd(int fd, const sigset_t* mask, int flags);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SIGNALFD_H */
