/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_STAT_H
#define _WASMUX_STAT_H

#include <wasmux/types.h>

#define STATX_BASIC_STATS 0x000007ffU

struct statx_timestamp {
  int64_t tv_sec;
  uint32_t tv_nsec;
  int32_t __reserved;
};

struct statx {
  /* 0x00 */
  uint32_t stx_mask;
  uint32_t stx_blksize;
  uint64_t stx_attributes;
  /* 0x10 */
  uint32_t stx_nlink;
  uint32_t stx_uid;
  uint32_t stx_gid;
  uint16_t stx_mode;
  uint16_t __spare0[1];
  /* 0x20 */
  uint64_t stx_ino;
  uint64_t stx_size;
  uint64_t stx_blocks;
  uint64_t stx_attributes_mask;
  /* 0x40 */
  struct statx_timestamp stx_atime;
  struct statx_timestamp stx_btime;
  struct statx_timestamp stx_ctime;
  struct statx_timestamp stx_mtime;
  /* 0x80 */
  uint32_t stx_rdev_major;
  uint32_t stx_rdev_minor;
  uint32_t stx_dev_major;
  uint32_t stx_dev_minor;
  /* 0x90 */
  uint64_t stx_mnt_id;
  uint32_t stx_dio_mem_align;
  uint32_t stx_dio_offset_align;
  /* 0xa0 */
  uint64_t stx_subvol;
  uint32_t stx_atomic_write_unit_min;
  uint32_t stx_atomic_write_unit_max;
  /* 0xb0 */
  uint32_t stx_atomic_write_segments_max;
  uint32_t __spare1[1];
  /* 0xb8 */
  uint64_t __spare3[9];
  /* 0x100 */
};


#endif /* _WASMUX_STAT_H */
