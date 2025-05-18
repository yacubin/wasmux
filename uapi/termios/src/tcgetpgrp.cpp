/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>
#include <wasmux/arch/syscalls.h>

#include <unistd.h>
#include <sys/ioctl.h>

__ATTR_HIDDEN
extern "C" pid_t __tcgetpgrp(int fd)
{
	int pgrp;
	if (ioctl(fd, TIOCGPGRP, &pgrp) < 0)
    pgrp = -1;
	return static_cast<pid_t>(pgrp);
}

extern "C" __ATTR_ALIAS(__tcgetpgrp, tcgetpgrp) __ATTR_WEAK;
