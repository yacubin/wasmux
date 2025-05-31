/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ARCH_SYSCALLS_DEFINE_H
#define _WASMUX_ARCH_SYSCALLS_DEFINE_H

#include <wasmux/export.h>

#define SYSCALL_DEFINE0(name) \
  __EXPORT long sys_##name(void); \
  __EXPORT long __seal_sys_##name(void) \
  { \
    return sys_##name(); \
  } \
  __EXPORT long sys_##name(void)

#define SYSCALL_DEFINE1(name, t1, a1) \
  __EXPORT long sys_##name(t1 a1); \
  __EXPORT long __seal_sys_##name(long p1) \
  { \
    return sys_##name((t1)p1); \
  } \
  __EXPORT long sys_##name(t1 a1)

#define SYSCALL_DEFINE2(name, t1, a1, t2, a2) \
  __EXPORT long sys_##name(t1 a1, t2 a2); \
  __EXPORT long __seal_sys_##name(long p1, long p2) \
  { \
    return sys_##name((t1)p1, (t2)p2); \
  } \
  __EXPORT long sys_##name(t1 a1, t2 a2)

#define SYSCALL_DEFINE3(name, t1, a1, t2, a2, t3, a3) \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3); \
  __EXPORT long __seal_sys_##name(long p1, long p2, long p3) \
  { \
    return sys_##name((t1)p1, (t2)p2, (t3)p3); \
  } \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3)

#define SYSCALL_DEFINE4(name, t1, a1, t2, a2, t3, a3, t4, a4) \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3, t4 a4); \
  __EXPORT long __seal_sys_##name(long p1, long p2, long p3, long p4) \
  { \
    return sys_##name((t1)p1, (t2)p2, (t3)p3, (t4)p4); \
  } \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3, t4 a4)

#define SYSCALL_DEFINE5(name, t1, a1, t2, a2, t3, a3, t4, a4, t5, a5) \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3, t4 a4, t5 a5); \
  __EXPORT long __seal_sys_##name(long p1, long p2, long p3, long p4, long p5) \
  { \
    return sys_##name((t1)p1, (t2)p2, (t3)p3, (t4)p4, (t5)p5); \
  } \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3, t4 a4, t5 a5)

#define SYSCALL_DEFINE6(name, t1, a1, t2, a2, t3, a3, t4, a4, t5, a5, t6, a6) \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3, t4 a4, t5 a5, t6 a6); \
  __EXPORT long __seal_sys_##name(long p1, long p2, long p3, long p4, long p5, long p6) \
  { \
    return sys_##name((t1)p1, (t2)p2, (t3)p3, (t4)p4, (t5)p5, (t6)p6); \
  } \
  __EXPORT long sys_##name(t1 a1, t2 a2, t3 a3, t4 a4, t5 a5, t6 a6)

#endif /* _WASMUX_ARCH_SYSCALLS_DEFINE_H */
