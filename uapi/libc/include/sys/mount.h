/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_MOUNT_H
#define _SYS_MOUNT_H

#include <wasmux/ioctl.h>
#include <wasmux/mount.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BLKGETSIZE _IO(0x12,96)
#define BLKFLSBUF  _IO(0x12,97)
#define BLKSSZGET  _IO(0x12,104)

#define MS_RELATIME (1 << 21)

int mount(const char* special, const char* dir, const char* fstype, unsigned long flags, const void* data);
int umount(const char* special);
int umount2(const char* special, int flags);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_MOUNT_H */
