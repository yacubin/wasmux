/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_STATVFS_H
#define _WASMUX_STATVFS_H

#include <wasmux/types.h>
#include <wasmux/posix_types.h>
#include <wasmux/fsblkcnt.h>
#include <wasmux/fsfilcnt.h>

struct statvfs {
  unsigned long f_bsize;
  unsigned long f_frsize;
  fsblkcnt_t f_blocks;
  fsblkcnt_t f_bfree;
  fsblkcnt_t f_bavail;
  fsfilcnt_t f_files;
  fsfilcnt_t f_ffree;
  fsfilcnt_t f_favail;
  __kernel_fsid_t f_fsid;
  unsigned long f_flags;
  unsigned long f_namemax;
  unsigned f_type;
  unsigned f_spare[5];
};

#endif /* _WASMUX_STATVFS_H */
