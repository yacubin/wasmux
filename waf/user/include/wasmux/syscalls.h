/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SYSCALLS_H
#define _WASMUX_SYSCALLS_H

#include <wasmux/types.h>
#include <wasmux/time.h>
#include <wasmux/arch-syscall.h>
#include <wasmux/compiler.h>
#include <wasmux/wainst_names.h>

#ifdef __cplusplus
extern "C" {
#endif

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL0)
long __kernel_syscall0(long number);

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL1)
long __kernel_syscall1(long number, long arg1);

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL2)
long __kernel_syscall2(long number, long arg1, long arg2);

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL3)
long __kernel_syscall3(long number, long arg1, long arg2, long arg3);

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL4)
long __kernel_syscall4(long number, long arg1, long arg2, long arg3, long arg4);

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL5)
long __kernel_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);

__ATTR_IMPORT_NAME(WASMUX_KERNEL_MODULE, WASMUX_KERNEL_SYSCALL6)
long __kernel_syscall6(long number, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6);

#define __SYSCALL_ARG0(nr, a1, a2, a3, a4, a5, a6) nr
#define __SYSCALL_ARG1(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1)
#define __SYSCALL_ARG2(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2)
#define __SYSCALL_ARG3(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3)
#define __SYSCALL_ARG4(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3), (long)(a4)
#define __SYSCALL_ARG5(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5)
#define __SYSCALL_ARG6(nr, a1, a2, a3, a4, a5, a6) nr, (long)(a1), (long)(a2), (long)(a3), (long)(a4), (long)(a5), (long)(a6)

#define __SYSCALL_CALL(m, name, a1, a2, a3, a4, a5, a6, n, ...) \
  __kernel_syscall##n(__SYSCALL_ARG##n(m(name), a1, a2, a3, a4, a5, a6))

#define __SC_NR_CAST(name) __NR_##name
#define __SR_NO_CAST(name) name

#define ___DO_SYSCALL(...) __SYSCALL_CALL(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define __DO_SYSCALL(...) ___DO_SYSCALL(__SC_NR_CAST, __VA_ARGS__)
#define __DO_SYSCALL_NR(...) ___DO_SYSCALL(__SR_NO_CAST, __VA_ARGS__)

#define __SYSCALL __DO_SYSCALL

static inline long sys_write(unsigned int fd, const char* buf, size_t count)
{
  return __DO_SYSCALL(write, fd, buf, count);
}

static inline long sys_close(unsigned int fd)
{
  return __DO_SYSCALL(close, fd);
}

static inline long sys_getcwd(char* buf, unsigned long len)
{
  return __DO_SYSCALL(getcwd, buf, len);
}

static inline long sys_gettid(void)
{
  return __DO_SYSCALL(gettid);
}

static inline long sys_ioctl(unsigned int fd, unsigned int cmd, unsigned long arg)
{
  return __DO_SYSCALL(ioctl, fd, cmd, arg);
}

static inline long sys_fork(void)
{
  return __DO_SYSCALL(fork);
}

static inline long sys_exit(int error_code)
{
  return __DO_SYSCALL(exit, error_code);
}

static inline long sys_link(const char* oldname, const char* newname)
{
  return __DO_SYSCALL(link, oldname, newname);
}

static inline long sys_unlink(const char* pathname)
{
  return __DO_SYSCALL(unlink, pathname);
}

static inline long sys_execve(const char* filename, const char* const* argv, const char* const* envp)
{
  return __DO_SYSCALL(execve, filename, argv, envp);
}

static inline long sys_chdir(const char* filename)
{
  return __DO_SYSCALL(chdir, filename);
}

static inline long sys_mknod(const char* filename, umode_t mode, unsigned dev)
{
  return __DO_SYSCALL(mknod, filename, mode, dev);
}

static inline long sys_getuid(void)
{
  return __DO_SYSCALL(getuid32);
}

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_SYSCALLS_H */
