/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_SENDFILE_H
#define _SYS_SENDFILE_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

ssize_t sendfile(int out_fd, int in_fd, off_t* ofs, size_t count);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SENDFILE_H */
