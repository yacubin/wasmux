/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_UIO_H
#define _WA_LIBC_SYS_UIO_H

#include <kernel/types.h>

struct iovec {
  void*  iov_base;  // Pointer to the data buffer
  size_t iov_len;   // Length of the data buffer
};

#endif /* _WA_LIBC_SYS_UIO_H */
