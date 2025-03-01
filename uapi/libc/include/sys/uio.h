/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#include <wasmux/uio.h>

#ifdef __cplusplus
extern "C" {
#endif

ssize_t readv(int fd, const struct iovec* iov, int count);
ssize_t writev(int fd, const struct iovec* iov, int count);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_UIO_H */
