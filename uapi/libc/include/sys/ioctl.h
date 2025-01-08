/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_IOCTL_H
#define _WA_LIBC_SYS_IOCTL_H

#include <wasmux/types.h>
#include <wasmux/ioctls.h>
#include <wasmux/termios.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _IOR(t, nr, type) 0
#define _IOW(t, nr, type) 0
#define _IOWR(t, nr, type) 0

int ioctl(int fd, int request, ...);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_IOCTL_H */
