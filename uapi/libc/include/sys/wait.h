/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_WAIT_H
#define _WA_LIBC_SYS_WAIT_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WNOHANG 1
#define WUNTRACED 2

#define WEXITSTATUS(status) (((status) & 0xff00) >> 8)
#define WIFEXITED(status)   (((status) & 0x7f) == 0)
#define WTERMSIG(status)    ((status) & 0x7f)
#define WIFSIGNALED(status) ((status) - 1 < 0xff)
#define WIFSTOPPED(status)  (((status) & 0xff) == 0x7f)

pid_t wait(int* stat_loc);
pid_t waitpid(pid_t pid, int* stat_loc, int options);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_WAIT_H */
