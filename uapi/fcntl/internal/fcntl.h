/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _INTERNAL_FCNTL_H
#define _INTERNAL_FCNTL_H

#include_next <fcntl.h>
#include <wasmux/compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

int __creat(const char* path, mode_t mode) __ATTR_HIDDEN;
int __open(const char* path, int flags, ...) __ATTR_HIDDEN;
int __openat(int dirfd, const char* path, int flags, ...) __ATTR_HIDDEN;

#ifdef __cplusplus
}
#endif

#endif /* _INTERNAL_FCNTL_H */
