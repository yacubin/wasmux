/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN
extern "C" int __fstatat(int dirfd, const char* path, struct stat* buf, int flags)
{
  struct statx tmp;

  int ret = statx(dirfd, path, flags, STATX_BASIC_STATS, &tmp);
  if (ret == 0) {
    *buf = (struct stat) {
      .st_dev = makedev(tmp.stx_dev_major, tmp.stx_dev_minor),
      .st_ino = tmp.stx_ino,
      .st_mode = tmp.stx_mode,
      .st_nlink = tmp.stx_nlink,
      .st_uid = tmp.stx_uid,
      .st_gid = tmp.stx_gid,
      .st_rdev = makedev(tmp.stx_rdev_major, tmp.stx_rdev_minor),
      // FIXME: Should be without cast
      .st_size = static_cast<off_t>(tmp.stx_size),
      .st_blksize = static_cast<blksize_t>(tmp.stx_blksize),
      .st_blocks = static_cast<blkcnt_t>(tmp.stx_blocks),
      .st_atim.tv_sec = tmp.stx_atime.tv_sec,
      .st_atim.tv_nsec = static_cast<long>(tmp.stx_atime.tv_nsec),
      .st_mtim.tv_sec = tmp.stx_mtime.tv_sec,
      .st_mtim.tv_nsec = static_cast<long>(tmp.stx_mtime.tv_nsec),
      .st_ctim.tv_sec = tmp.stx_ctime.tv_sec,
      .st_ctim.tv_nsec = static_cast<long>(tmp.stx_ctime.tv_nsec),
    };
  }

  return ret;
}

extern "C" __ATTR_ALIAS(__fstatat, fstatat) __ATTR_WEAK;
