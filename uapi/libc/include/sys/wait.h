/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_WAIT_H
#define _SYS_WAIT_H

#include <sys/types.h>
#include <bits/waitstatus.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WNOHANG 1
#define WUNTRACED 2

pid_t wait(int* stat_loc);
pid_t waitpid(pid_t pid, int* stat_loc, int options);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_WAIT_H */
