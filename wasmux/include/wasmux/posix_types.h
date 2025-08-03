/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_POSIX_TYPES_H
#define _WASMUX_POSIX_TYPES_H

#define	FD_SETSIZE 1024

typedef unsigned long fd_mask;

typedef struct {
  fd_mask fds_bits[FD_SETSIZE / (8 * sizeof(fd_mask))];
} fd_set;

typedef struct {
  int val[2];
} __kernel_fsid_t;

#endif /* _WASMUX_POSIX_TYPES_H */
