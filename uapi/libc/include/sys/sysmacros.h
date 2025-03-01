/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline dev_t __inline_makedev(unsigned major, unsigned minor)
{
  return ((dev_t)major & 0xfffff000u) << 32
       | ((dev_t)major & 0x00000fffu) << 8
       | ((dev_t)minor & 0xffffff00u) << 12
       | ((dev_t)minor & 0x000000ffu) << 0;
}

static inline unsigned __inline_major(dev_t dev)
{
  return ((dev >> 32) & 0xfffff000u)
       | ((dev >> 8) & 0x00000fffu);
}

static inline unsigned __inline_minor(dev_t dev)
{
  return ((dev >> 12) & 0xffffff00u)
       | ((dev >> 0) & 0x000000ffu);
}

#define makedev(major, minor) __inline_makedev(major, minor)
#define major(dev) __inline_major(dev)
#define minor(dev) __inline_minor(dev)

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SYSMACROS_H */
