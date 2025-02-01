/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_EVENTFD_H
#define _SYS_EVENTFD_H

#include <wasmux/eventfd.h>

#ifdef __cplusplus
extern "C" {
#endif

int eventfd(unsigned count, int flags);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_EVENTFD_H */
