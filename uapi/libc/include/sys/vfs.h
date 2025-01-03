/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_VFS_H
#define _WA_LIBC_SYS_VFS_H

#include <kernel/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int	val[2];
} fsid_t;

struct statfs {
  unsigned int f_type;
  unsigned int f_bsize;
  uint64_t f_blocks;
  uint64_t f_bfree;
  uint64_t f_bavail;
  uint64_t f_files;
  uint64_t f_ffree;
  fsid_t f_fsid;
  unsigned int f_namelen;
  unsigned int f_spare[6];
};

int statfs(const char* path, struct statfs* buf);
int fstatfs(int fd, struct statfs* buf);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_VFS_H */
