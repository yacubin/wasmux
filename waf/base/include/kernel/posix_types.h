/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_POSIX_TYPES_H
#define _WA_KERNEL_POSIX_TYPES_H

#define	FD_SETSIZE 256

typedef struct {
  int dummy;
} fd_set;

typedef struct {
  int val[2];
} __kernel_fsid_t;

#endif /* _WA_KERNEL_POSIX_TYPES_H */
