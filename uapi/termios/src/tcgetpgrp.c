/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <unistd.h>
#include <sys/ioctl.h>

#include <wasmux/export.h>
#include <wasmux/compiler.h>
#include <wasmux/syscalls.h>

__ATTR_HIDDEN __EXPORT
pid_t __tcgetpgrp(int fd)
{
	int pgrp;
	if (ioctl(fd, TIOCGPGRP, &pgrp) < 0)
    pgrp = -1;
	return (pid_t)pgrp;
}

__EXPORT __ATTR_ALIAS(__tcgetpgrp, tcgetpgrp) __ATTR_WEAK;
