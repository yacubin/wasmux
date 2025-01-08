/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_UIO_H
#define _WA_LIBC_SYS_UIO_H

#include <wasmux/types.h>

struct iovec {
  void*  iov_base;  // Pointer to the data buffer
  size_t iov_len;   // Length of the data buffer
};

ssize_t readv(int fd, const struct iovec* iov, int count);
ssize_t writev(int fd, const struct iovec* iov, int count);

#endif /* _WA_LIBC_SYS_UIO_H */
