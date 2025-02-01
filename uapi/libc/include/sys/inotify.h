/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_INOTIFY_H
#define _SYS_INOTIFY_H

#include <wasmux/inotify.h>

#ifdef __cplusplus
extern "C" {
#endif

int inotify_init1(int flags);
int inotify_add_watch(int fd, const char* name, unsigned mask);
int inotify_rm_watch(int fd, int wd);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_INOTIFY_H */
