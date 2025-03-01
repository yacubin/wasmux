/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_FCNTL_H
#define _WASMUX_FCNTL_H

#define AT_SYMLINK_NOFOLLOW 0x100

#ifndef O_APPEND
#define O_APPEND    00002000
#endif
#ifndef O_NONBLOCK
#define O_NONBLOCK  00004000
#endif
#ifndef O_DIRECTORY
#define O_DIRECTORY	00200000
#endif
#ifndef O_CLOEXEC
#define O_CLOEXEC   02000000
#endif

#ifndef __O_TMPFILE
#define __O_TMPFILE 020000000
#endif

#define O_TMPFILE (__O_TMPFILE | O_DIRECTORY)

#define FD_CLOEXEC 1

#endif /* _WASMUX_FCNTL_H */
