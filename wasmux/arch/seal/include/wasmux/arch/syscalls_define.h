/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ARCH_SYSCALLS_DEFINE_H
#define _WASMUX_ARCH_SYSCALLS_DEFINE_H

#include <wasmux/export.h>
#include <wasmux/compiler.h>

#define __MAP0(m, ...)
#define __MAP1(m, t, a, ...) m(t, a)
#define __MAP2(m, t, a, ...) m(t, a), __MAP1(m, __VA_ARGS__)
#define __MAP3(m, t, a, ...) m(t, a), __MAP2(m, __VA_ARGS__)
#define __MAP4(m, t, a, ...) m(t, a), __MAP3(m, __VA_ARGS__)
#define __MAP5(m, t, a, ...) m(t, a), __MAP4(m, __VA_ARGS__)
#define __MAP6(m, t, a, ...) m(t, a), __MAP5(m, __VA_ARGS__)
#define __MAP(n, ...) __MAP##n(__VA_ARGS__)

#define __SC_DECL(t, a) t a
#define __SC_LONG(t, a) long a
#define __SC_CAST(t, a) (t) a
#define __SC_ARGS(t, a) a

#define __SYSCALL_DEFINE0(name) \
  __EXPORT long sys_##name(void); \
  __EXPORT long __seal_sys_##name(void) \
  { \
    return sys_##name(); \
  } \
  long sys_##name(void)

#define __SYSCALL_DEFINEx(x, name, ...) \
  __EXPORT long sys_##name(__MAP(x, __SC_DECL, __VA_ARGS__)); \
  __EXPORT long __seal_sys_##name(__MAP(x, __SC_LONG, __VA_ARGS__)) \
  { \
    return sys_##name(__MAP(x, __SC_ARGS, __VA_ARGS__)); \
  } \
  long sys_##name(__MAP(x, __SC_DECL, __VA_ARGS__))

#define SYSCALL_DEFINE0(name)      __SYSCALL_DEFINE0(name)
#define SYSCALL_DEFINE1(name, ...) __SYSCALL_DEFINEx(1, name, __VA_ARGS__)
#define SYSCALL_DEFINE2(name, ...) __SYSCALL_DEFINEx(2, name, __VA_ARGS__)
#define SYSCALL_DEFINE3(name, ...) __SYSCALL_DEFINEx(3, name, __VA_ARGS__)
#define SYSCALL_DEFINE4(name, ...) __SYSCALL_DEFINEx(4, name, __VA_ARGS__)
#define SYSCALL_DEFINE5(name, ...) __SYSCALL_DEFINEx(5, name, __VA_ARGS__)
#define SYSCALL_DEFINE6(name, ...) __SYSCALL_DEFINEx(6, name, __VA_ARGS__)

#endif /* _WASMUX_ARCH_SYSCALLS_DEFINE_H */
