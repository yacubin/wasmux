/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_VFS_H
#define _SYS_VFS_H

#include <wasmux/statfs.h>

#ifdef __cplusplus
extern "C" {
#endif

int statfs(const char* path, struct statfs* buf);
int fstatfs(int fd, struct statfs* buf);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_VFS_H */
