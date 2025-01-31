/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_STATFS_H
#define _WASMUX_STATFS_H

#include <wasmux/types.h>
#include <wasmux/posix_types.h>

#ifndef __fsblkcnt_t
#define __fsblkcnt_t uint64_t
#endif

struct statfs {
  unsigned f_type;
  unsigned f_bsize;
  __fsblkcnt_t f_blocks;
  __fsblkcnt_t f_bfree;
  __fsblkcnt_t f_bavail;
  __fsblkcnt_t f_files;
  __fsblkcnt_t f_ffree;
  __kernel_fsid_t f_fsid;
  unsigned f_namelen;
  unsigned f_frsize;
  unsigned f_flags;
  unsigned f_spare[4];
};

#endif /* _WASMUX_STATFS_H */
