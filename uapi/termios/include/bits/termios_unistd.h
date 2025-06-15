/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _BITS_TERMIOS_UNISTD_H
#define _BITS_TERMIOS_UNISTD_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

int isatty(int fd);
char* ttyname(int fd);
int ttyname_r(int fd, char* buf, size_t len);
pid_t tcgetpgrp(int fd);
int tcsetpgrp(int fd, pid_t pidgrp);

#ifdef __cplusplus
}
#endif

#endif /* _BITS_TERMIOS_UNISTD_H */
