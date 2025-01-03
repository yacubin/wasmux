/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_SYSMACROS_H
#define _WA_LIBC_SYS_SYSMACROS_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

dev_t makedev(unsigned major, unsigned minor);
unsigned major(dev_t dev);
unsigned minor(dev_t dev);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_SYSMACROS_H */
