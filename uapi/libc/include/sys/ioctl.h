/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H

#include <wasmux/types.h>
#include <wasmux/ioctl.h>
#include <wasmux/ioctls.h>
#include <wasmux/sockios.h>
#include <wasmux/termios.h>

#ifdef __cplusplus
extern "C" {
#endif

int ioctl(int fd, int request, ...);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_IOCTL_H */
