/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_STATFS_H
#define _WA_KERNEL_STATFS_H

#include <wasmux/posix_types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct statfs {
  unsigned f_type;
  unsigned f_bsize;
  unsigned f_blocks;
  unsigned f_bfree;
  unsigned f_bavail;
  unsigned f_files;
  unsigned f_ffree;
  __kernel_fsid_t f_fsid;
  unsigned f_namelen;
  unsigned f_frsize;
  unsigned f_flags;
  unsigned f_spare[4];
};

#ifdef __cplusplus
}
#endif

#endif /* _WA_KERNEL_STATFS_H */
