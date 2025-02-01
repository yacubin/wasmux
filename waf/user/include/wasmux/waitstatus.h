/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_WAITSTATUS_H
#define _SYS_WAITSTATUS_H

#define WEXITSTATUS(status) (((status) & 0xff00) >> 8)
#define WIFEXITED(status)   (((status) & 0x7f) == 0)
#define WTERMSIG(status)    ((status) & 0x7f)
#define WIFSIGNALED(status) ((status) - 1 < 0xff)
#define WIFSTOPPED(status)  (((status) & 0xff) == 0x7f)

#endif /* _SYS_WAITSTATUS_H */
