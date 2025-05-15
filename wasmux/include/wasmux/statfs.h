/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_STATFS_H
#define _WASMUX_STATFS_H

#include <wasmux/types.h>
#include <wasmux/posix_types.h>
#include <wasmux/fsblkcnt.h>
#include <wasmux/fsfilcnt.h>

struct statfs {
  unsigned f_type;
  unsigned f_bsize;
  fsblkcnt_t f_blocks;
  fsblkcnt_t f_bfree;
  fsblkcnt_t f_bavail;
  fsfilcnt_t f_files;
  fsfilcnt_t f_ffree;
  __kernel_fsid_t f_fsid;
  unsigned f_namelen;
  unsigned f_frsize;
  unsigned f_flags;
  unsigned f_spare[4];
};

#endif /* _WASMUX_STATFS_H */
