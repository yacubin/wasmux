/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_UIO_H
#define _WASMUX_UIO_H

#include <wasmux/types.h>

struct iovec {
  void*  iov_base;  // Pointer to the data buffer
  size_t iov_len;   // Length of the data buffer
};

#endif /* _WASMUX_UIO_H */
