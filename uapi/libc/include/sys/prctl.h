/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_PRCTL_H
#define _SYS_PRCTL_H

#include <wasmux/prctl.h>

#ifdef __cplusplus
extern "C" {
#endif

int prctl(int option, ...);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_PRCTL_H */
