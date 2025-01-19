/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SYSCALLS_H
#define _WASMUX_SYSCALLS_H

#include <wasmux/types.h>
#include <wasmux/syscall-nums.h>

#ifdef __cplusplus
extern "C" {
#endif

#define WX_SYSINST_NAME "kernel"
#define WX_SYSCALL_NAME0 "_syscall0"
#define WX_SYSCALL_NAME1 "_syscall1"
#define WX_SYSCALL_NAME2 "_syscall2"
#define WX_SYSCALL_NAME3 "_syscall3"
#define WX_SYSCALL_NAME4 "_syscall4"
#define WX_SYSCALL_NAME5 "_syscall5"
#define WX_SYSCALL_NAME6 "_syscall6"

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME0)))
long __kernel_syscall0(long number);

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME1)))
long __kernel_syscall1(long number, long arg1);

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME2)))
long __kernel_syscall2(long number, long arg1, long arg2);

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME3)))
long __kernel_syscall3(long number, long arg1, long arg2, long arg3);

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME4)))
long __kernel_syscall4(long number, long arg1, long arg2, long arg3, long arg4);

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME5)))
long __kernel_syscall5(long number, long arg1, long arg2, long arg3, long arg4, long arg5);

__attribute__((import_module(WX_SYSINST_NAME), import_name(WX_SYSCALL_NAME6)))
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

#define __SC_NR_CAST(name) SYS_##name
#define __SR_NO_CAST(name) name

#define ___DO_SYSCALL(...) __SYSCALL_CALL(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define __DO_SYSCALL(...) ___DO_SYSCALL(__SC_NR_CAST, __VA_ARGS__)
#define __DO_SYSCALL_NR(...) ___DO_SYSCALL(__SR_NO_CAST, __VA_ARGS__)

static inline long sys_open(const char* filename, int flags, umode_t mode)
{
  return __DO_SYSCALL(open, filename, flags, mode);
}

static inline long sys_read(unsigned int fd, char* buf, size_t count)
{
  return __DO_SYSCALL(read, fd, buf, count);
}

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

static inline long sys_brk(unsigned long brk)
{
  return __DO_SYSCALL(brk, brk);
}

static inline long sys_fork(void)
{
  return __DO_SYSCALL(fork);
}

static inline long sys_exit(int error_code)
{
  return __DO_SYSCALL(exit, error_code);
}

static inline long sys_waitpid(pid_t pid, int* stat_addr, int options)
{
  return __DO_SYSCALL(waitpid, pid, stat_addr, options);
}

static inline long sys_creat(const char* path, umode_t mode)
{
  return __DO_SYSCALL(creat, path, mode);
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
  return __DO_SYSCALL(getuid);
}

static inline long sys_getgid(void)
{
  return __DO_SYSCALL(getgid);
}

static inline long sys_geteuid(void)
{
  return __DO_SYSCALL(geteuid);
}

static inline long sys_getegid(void)
{
  return __DO_SYSCALL(getegid);
}

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_SYSCALLS_H */
