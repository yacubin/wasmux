/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_INOTIFY_H
#define _WASMUX_INOTIFY_H

#ifdef __cplusplus
extern "C" {
#endif

struct inotify_event {
  int wd;
  unsigned mask;
  unsigned cookie;
  unsigned len;
  char name[];
};

#define IN_MODIFY        0x00000002
#define IN_ATTRIB        0x00000004
#define IN_CLOSE_WRITE   0x00000008
#define IN_CLOSE_NOWRITE 0x00000010
#define IN_MOVED_FROM    0x00000040
#define IN_MOVED_TO      0x00000080
#define IN_CREATE        0x00000100
#define IN_DELETE        0x00000200
#define IN_ONLYDIR       0x01000000
#define IN_ISDIR         0x40000000

#define IN_CLOSE      (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE)
#define IN_MOVE       (IN_MOVED_FROM | IN_MOVED_TO)

#define IN_DONT_FOLLOW 0x02000000

#define IN_CLOEXEC     O_CLOEXEC
#define IN_NONBLOCK    O_NONBLOCK

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_INOTIFY_H */
