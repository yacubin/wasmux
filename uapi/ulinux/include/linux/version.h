/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LINUX_VERSION_H
#define _LINUX_VERSION_H

#define LINUX_VERSION_CODE 395527
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + ((c) > 255 ? 255 : (c)))
#define LINUX_VERSION_MAJOR 6
#define LINUX_VERSION_PATCHLEVEL 9
#define LINUX_VERSION_SUBLEVEL 7

#endif /* _LINUX_VERSION_H */
