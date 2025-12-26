/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <wasmux/compiler.h>
#include <wasmux/export.h>

__EXPORT __ATTR_HIDDEN
int __fstatat(int dirfd, const char* path, struct stat* buf, int flags)
{
  struct statx tmp;

  int ret = statx(dirfd, path, flags, STATX_BASIC_STATS, &tmp);
  if (ret == 0) {
    buf->st_dev = makedev(tmp.stx_dev_major, tmp.stx_dev_minor);
    buf->st_ino = tmp.stx_ino;
    buf->st_mode = tmp.stx_mode;
    buf->st_nlink = tmp.stx_nlink;
    buf->st_uid = tmp.stx_uid;
    buf->st_gid = tmp.stx_gid;
    buf->st_rdev = makedev(tmp.stx_rdev_major, tmp.stx_rdev_minor);
    // FIXME: Should be without cast
    buf->st_size = (off_t)tmp.stx_size;
    buf->st_blksize = (blksize_t)tmp.stx_blksize;
    buf->st_blocks = (blkcnt_t)tmp.stx_blocks;
    buf->st_atim.tv_sec = tmp.stx_atime.tv_sec;
    buf->st_atim.tv_nsec = (long)tmp.stx_atime.tv_nsec;
    buf->st_mtim.tv_sec = tmp.stx_mtime.tv_sec;
    buf->st_mtim.tv_nsec = (long)tmp.stx_mtime.tv_nsec;
    buf->st_ctim.tv_sec = tmp.stx_ctime.tv_sec;
    buf->st_ctim.tv_nsec = (long)tmp.stx_ctime.tv_nsec;
  }

  return ret;
}

__EXPORT __ATTR_WEAK_ALIAS(__fstatat, fstatat);
