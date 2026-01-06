/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_XATTR_H
#define _SYS_XATTR_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XATTR_CREATE  (1 << 0) /* Set the extended attribute only if it does not exist */
#define XATTR_REPLACE (1 << 1) /* Set the extended attribute only if it already exists */

ssize_t fgetxattr(int fd, const char* name, void* value, size_t size);
int fsetxattr(int fd, const char* name, const void* value, size_t size, int flags);
ssize_t flistxattr(int fd, char* list, size_t size);
int fremovexattr(int fd, const char* name);

ssize_t getxattr(const char* path, const char* name, void* value, size_t size);
int setxattr(const char* path, const char* name, const void* value, size_t size, int flags);
ssize_t listxattr(const char* path, char* list, size_t size);
int removexattr(const char* path, const char* name);

ssize_t lgetxattr(const char* path, const char* name, void* value, size_t size);
int lsetxattr(const char* path, const char* name,  const void* value, size_t size, int flags);
ssize_t llistxattr(const char* path, char* list, size_t size);
int lremovexattr(const char* path, const char* name);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_XATTR_H */
