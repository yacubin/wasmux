/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_IOCTL_H
#define _WA_LIBC_SYS_IOCTL_H

#include <kernel/types.h>
#include <kernel/ioctls.h>

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
