/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_CPU_SET_H
#define _WASMUX_CPU_SET_H

typedef unsigned long __cpu_mask;

#define __CPU_SETSIZE 1024
#define __NCPUBITS (sizeof(__cpu_mask) * 8)

typedef struct __cpu_set_struct {
  __cpu_mask __bits[__CPU_SETSIZE/__NCPUBITS];
};

typedef struct __cpu_set_struct cpu_set_t;

#endif /* _WASMUX_CPU_SET_H */
