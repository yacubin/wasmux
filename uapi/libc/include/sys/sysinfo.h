/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_SYSINFO_H
#define _SYS_SYSINFO_H

#include <wasmux/sysinfo.h>

#ifdef __cplusplus
extern "C" {
#endif

int sysinfo(struct sysinfo* info);
int get_nprocs(void);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SYSINFO_H */
