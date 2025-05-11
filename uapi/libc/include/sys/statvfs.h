/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_STATVFS_H
#define _SYS_STATVFS_H

#include <wasmux/statvfs.h>

#ifdef __cplusplus
extern "C" {
#endif

int statvfs(const char* path, struct statvfs* buf);
int fstatvfs(int fd, struct statvfs* buf);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_STATVFS_H */
