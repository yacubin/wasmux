
#ifndef _WASMUX_ARCH_ARCH_SYSCALL_H
#define _WASMUX_ARCH_ARCH_SYSCALL_H

#ifdef __cplusplus
extern "C" {
#endif

long __seal_sys_restart_syscall(void);
long __seal_sys_exit(long a1);
long __seal_sys_fork(void);
long __seal_sys_read(long a1, long a2, long a3);
long __seal_sys_write(long a1, long a2, long a3);
long __seal_sys_open(long a1, long a2, long a3);
long __seal_sys_close(long a1);
long __seal_sys_waitpid(long a1, long a2, long a3);
long __seal_sys_creat(long a1, long a2);
long __seal_sys_link(long a1, long a2);
long __seal_sys_unlink(long a1);
long __seal_sys_execve(long a1, long a2, long a3);
long __seal_sys_chdir(long a1);
long __seal_sys_time32(long a1);
long __seal_sys_mknod(long a1, long a2, long a3);
long __seal_sys_chmod(long a1, long a2);
long __seal_sys_lchown16(long a1, long a2, long a3);
long __seal_sys_stat(long a1, long a2);
long __seal_sys_lseek(long a1, long a2, long a3);
long __seal_sys_getpid(void);
long __seal_sys_mount(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_oldumount(long a1);
long __seal_sys_setuid16(long a1);
long __seal_sys_getuid16(void);
long __seal_sys_stime32(long a1);
long __seal_sys_ptrace(long a1, long a2, long a3, long a4);
long __seal_sys_alarm(long a1);
long __seal_sys_fstat(long a1, long a2);
long __seal_sys_pause(void);
long __seal_sys_utime32(long a1, long a2);
long __seal_sys_access(long a1, long a2);
long __seal_sys_nice(long a1);
long __seal_sys_sync(void);
long __seal_sys_kill(long a1, long a2);
long __seal_sys_rename(long a1, long a2);
long __seal_sys_mkdir(long a1, long a2);
long __seal_sys_rmdir(long a1);
long __seal_sys_dup(long a1);
long __seal_sys_pipe(long a1);
long __seal_sys_times(long a1);
long __seal_sys_brk(long a1);
long __seal_sys_setgid16(long a1);
long __seal_sys_getgid16(void);
long __seal_sys_signal(long a1, long a2);
long __seal_sys_geteuid16(void);
long __seal_sys_getegid16(void);
long __seal_sys_acct(long a1);
long __seal_sys_umount(long a1, long a2);
long __seal_sys_ioctl(long a1, long a2, long a3);
long __seal_sys_fcntl(long a1, long a2, long a3);
long __seal_sys_setpgid(long a1, long a2);
long __seal_sys_olduname(long a1);
long __seal_sys_umask(long a1);
long __seal_sys_chroot(long a1);
long __seal_sys_ustat(long a1, long a2);
long __seal_sys_dup2(long a1, long a2);
long __seal_sys_getppid(void);
long __seal_sys_getpgrp(void);
long __seal_sys_setsid(void);
long __seal_sys_sigaction(long a1, long a2, long a3);
long __seal_sys_sgetmask(void);
long __seal_sys_ssetmask(long a1);
long __seal_sys_setreuid16(long a1, long a2);
long __seal_sys_setregid16(long a1, long a2);
long __seal_sys_sigsuspend(long a1);
long __seal_sys_sigpending(long a1);
long __seal_sys_sethostname(long a1, long a2);
long __seal_sys_setrlimit(long a1, long a2);
long __seal_sys_old_getrlimit(long a1, long a2);
long __seal_sys_getrusage(long a1, long a2);
long __seal_sys_gettimeofday(long a1, long a2);
long __seal_sys_settimeofday(long a1, long a2);
long __seal_sys_getgroups16(long a1, long a2);
long __seal_sys_setgroups16(long a1, long a2);
long __seal_sys_old_select(long a1);
long __seal_sys_symlink(long a1, long a2);
long __seal_sys_lstat(long a1, long a2);
long __seal_sys_readlink(long a1, long a2, long a3);
long __seal_sys_uselib(long a1);
long __seal_sys_swapon(long a1, long a2);
long __seal_sys_reboot(long a1, long a2, long a3, long a4);
long __seal_sys_old_readdir(long a1, long a2, long a3);
long __seal_sys_old_mmap(long a1);
long __seal_sys_munmap(long a1, long a2);
long __seal_sys_truncate(long a1, long a2);
long __seal_sys_ftruncate(long a1, long a2);
long __seal_sys_fchmod(long a1, long a2);
long __seal_sys_fchown16(long a1, long a2, long a3);
long __seal_sys_getpriority(long a1, long a2);
long __seal_sys_setpriority(long a1, long a2, long a3);
long __seal_sys_statfs(long a1, long a2);
long __seal_sys_fstatfs(long a1, long a2);
long __seal_sys_ioperm(long a1, long a2, long a3);
long __seal_sys_socketcall(long a1, long a2);
long __seal_sys_syslog(long a1, long a2, long a3);
long __seal_sys_setitimer(long a1, long a2, long a3);
long __seal_sys_getitimer(long a1, long a2);
long __seal_sys_newstat(long a1, long a2);
long __seal_sys_newlstat(long a1, long a2);
long __seal_sys_newfstat(long a1, long a2);
long __seal_sys_uname(long a1);
long __seal_sys_iopl(long a1);
long __seal_sys_vhangup(void);
long __seal_sys_wait4(long a1, long a2, long a3, long a4);
long __seal_sys_swapoff(long a1);
long __seal_sys_sysinfo(long a1);
long __seal_sys_ipc(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_fsync(long a1);
long __seal_sys_sigreturn(void);
long __seal_sys_clone(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_setdomainname(long a1, long a2);
long __seal_sys_newuname(long a1);
long __seal_sys_modify_ldt(long a1, long a2, long a3);
long __seal_sys_adjtimex_time32(long a1);
long __seal_sys_mprotect(long a1, long a2, long a3);
long __seal_sys_sigprocmask(long a1, long a2, long a3);
long __seal_sys_init_module(long a1, long a2, long a3);
long __seal_sys_delete_module(long a1, long a2);
long __seal_sys_quotactl(long a1, long a2, long a3, long a4);
long __seal_sys_getpgid(long a1);
long __seal_sys_fchdir(long a1);
long __seal_sys_sysfs(long a1, long a2, long a3);
long __seal_sys_personality(long a1);
long __seal_sys_setfsuid16(long a1);
long __seal_sys_setfsgid16(long a1);
long __seal_sys_llseek(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_getdents(long a1, long a2, long a3);
long __seal_sys_select(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_flock(long a1, long a2);
long __seal_sys_msync(long a1, long a2, long a3);
long __seal_sys_readv(long a1, long a2, long a3);
long __seal_sys_writev(long a1, long a2, long a3);
long __seal_sys_getsid(long a1);
long __seal_sys_fdatasync(long a1);
long __seal_sys_mlock(long a1, long a2);
long __seal_sys_munlock(long a1, long a2);
long __seal_sys_mlockall(long a1);
long __seal_sys_munlockall(void);
long __seal_sys_sched_setparam(long a1, long a2);
long __seal_sys_sched_getparam(long a1, long a2);
long __seal_sys_sched_setscheduler(long a1, long a2, long a3);
long __seal_sys_sched_getscheduler(long a1);
long __seal_sys_sched_yield(void);
long __seal_sys_sched_get_priority_max(long a1);
long __seal_sys_sched_get_priority_min(long a1);
long __seal_sys_sched_rr_get_interval_time32(long a1, long a2);
long __seal_sys_nanosleep_time32(long a1, long a2);
long __seal_sys_mremap(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_setresuid16(long a1, long a2, long a3);
long __seal_sys_getresuid16(long a1, long a2, long a3);
long __seal_sys_poll(long a1, long a2, long a3);
long __seal_sys_setresgid16(long a1, long a2, long a3);
long __seal_sys_getresgid16(long a1, long a2, long a3);
long __seal_sys_prctl(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_rt_sigreturn(long a1);
long __seal_sys_rt_sigaction(long a1, long a2, long a3, long a4);
long __seal_sys_rt_sigprocmask(long a1, long a2, long a3, long a4);
long __seal_sys_rt_sigpending(long a1, long a2);
long __seal_sys_rt_sigtimedwait_time32(long a1, long a2, long a3, long a4);
long __seal_sys_rt_sigqueueinfo(long a1, long a2, long a3);
long __seal_sys_rt_sigsuspend(long a1, long a2);
long __seal_sys_ia32_pread64(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_ia32_pwrite64(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_chown16(long a1, long a2, long a3);
long __seal_sys_getcwd(long a1, long a2);
long __seal_sys_capget(long a1, long a2);
long __seal_sys_capset(long a1, long a2);
long __seal_sys_sigaltstack(long a1, long a2);
long __seal_sys_sendfile(long a1, long a2, long a3, long a4);
long __seal_sys_vfork(void);
long __seal_sys_getrlimit(long a1, long a2);
long __seal_sys_mmap_pgoff(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_ia32_truncate64(long a1, long a2, long a3);
long __seal_sys_ia32_ftruncate64(long a1, long a2, long a3);
long __seal_sys_stat64(long a1, long a2);
long __seal_sys_lstat64(long a1, long a2);
long __seal_sys_fstat64(long a1, long a2);
long __seal_sys_lchown(long a1, long a2, long a3);
long __seal_sys_getuid(void);
long __seal_sys_getgid(void);
long __seal_sys_geteuid(void);
long __seal_sys_getegid(void);
long __seal_sys_setreuid(long a1, long a2);
long __seal_sys_setregid(long a1, long a2);
long __seal_sys_getgroups(long a1, long a2);
long __seal_sys_setgroups(long a1, long a2);
long __seal_sys_fchown(long a1, long a2, long a3);
long __seal_sys_setresuid(long a1, long a2, long a3);
long __seal_sys_getresuid(long a1, long a2, long a3);
long __seal_sys_setresgid(long a1, long a2, long a3);
long __seal_sys_getresgid(long a1, long a2, long a3);
long __seal_sys_chown(long a1, long a2, long a3);
long __seal_sys_setuid(long a1);
long __seal_sys_setgid(long a1);
long __seal_sys_setfsuid(long a1);
long __seal_sys_setfsgid(long a1);
long __seal_sys_pivot_root(long a1, long a2);
long __seal_sys_mincore(long a1, long a2, long a3);
long __seal_sys_madvise(long a1, long a2, long a3);
long __seal_sys_getdents64(long a1, long a2, long a3);
long __seal_sys_fcntl64(long a1, long a2, long a3);
long __seal_sys_gettid(void);
long __seal_sys_ia32_readahead(long a1, long a2, long a3, long a4);
long __seal_sys_setxattr(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_lsetxattr(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_fsetxattr(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_getxattr(long a1, long a2, long a3, long a4);
long __seal_sys_lgetxattr(long a1, long a2, long a3, long a4);
long __seal_sys_fgetxattr(long a1, long a2, long a3, long a4);
long __seal_sys_listxattr(long a1, long a2, long a3);
long __seal_sys_llistxattr(long a1, long a2, long a3);
long __seal_sys_flistxattr(long a1, long a2, long a3);
long __seal_sys_removexattr(long a1, long a2);
long __seal_sys_lremovexattr(long a1, long a2);
long __seal_sys_fremovexattr(long a1, long a2);
long __seal_sys_tkill(long a1, long a2);
long __seal_sys_sendfile64(long a1, long a2, long a3, long a4);
long __seal_sys_futex_time32(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_sched_setaffinity(long a1, long a2, long a3);
long __seal_sys_sched_getaffinity(long a1, long a2, long a3);
long __seal_sys_io_setup(long a1, long a2);
long __seal_sys_io_destroy(long a1);
long __seal_sys_io_getevents_time32(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_io_submit(long a1, long a2, long a3);
long __seal_sys_io_cancel(long a1, long a2, long a3);
long __seal_sys_ia32_fadvise64(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_exit_group(long a1);
long __seal_sys_epoll_create(long a1);
long __seal_sys_epoll_ctl(long a1, long a2, long a3, long a4);
long __seal_sys_epoll_wait(long a1, long a2, long a3, long a4);
long __seal_sys_remap_file_pages(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_set_tid_address(long a1);
long __seal_sys_timer_create(long a1, long a2, long a3);
long __seal_sys_timer_settime32(long a1, long a2, long a3, long a4);
long __seal_sys_timer_gettime32(long a1, long a2);
long __seal_sys_timer_getoverrun(long a1);
long __seal_sys_timer_delete(long a1);
long __seal_sys_clock_settime32(long a1, long a2);
long __seal_sys_clock_gettime32(long a1, long a2);
long __seal_sys_clock_getres_time32(long a1, long a2);
long __seal_sys_clock_nanosleep_time32(long a1, long a2, long a3, long a4);
long __seal_sys_statfs64(long a1, long a2, long a3);
long __seal_sys_fstatfs64(long a1, long a2, long a3);
long __seal_sys_tgkill(long a1, long a2, long a3);
long __seal_sys_utimes_time32(long a1, long a2);
long __seal_sys_ia32_fadvise64_64(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_mbind(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_get_mempolicy(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_set_mempolicy(long a1, long a2, long a3);
long __seal_sys_mq_open(long a1, long a2, long a3, long a4);
long __seal_sys_mq_unlink(long a1);
long __seal_sys_mq_timedsend_time32(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_mq_timedreceive_time32(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_mq_notify(long a1, long a2);
long __seal_sys_mq_getsetattr(long a1, long a2, long a3);
long __seal_sys_kexec_load(long a1, long a2, long a3, long a4);
long __seal_sys_waitid(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_add_key(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_request_key(long a1, long a2, long a3, long a4);
long __seal_sys_keyctl(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_ioprio_set(long a1, long a2, long a3);
long __seal_sys_ioprio_get(long a1, long a2);
long __seal_sys_inotify_init(void);
long __seal_sys_inotify_add_watch(long a1, long a2, long a3);
long __seal_sys_inotify_rm_watch(long a1, long a2);
long __seal_sys_migrate_pages(long a1, long a2, long a3, long a4);
long __seal_sys_openat(long a1, long a2, long a3, long a4);
long __seal_sys_mkdirat(long a1, long a2, long a3);
long __seal_sys_mknodat(long a1, long a2, long a3, long a4);
long __seal_sys_fchownat(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_futimesat_time32(long a1, long a2, long a3);
long __seal_sys_fstatat64(long a1, long a2, long a3, long a4);
long __seal_sys_unlinkat(long a1, long a2, long a3);
long __seal_sys_renameat(long a1, long a2, long a3, long a4);
long __seal_sys_linkat(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_symlinkat(long a1, long a2, long a3);
long __seal_sys_readlinkat(long a1, long a2, long a3, long a4);
long __seal_sys_fchmodat(long a1, long a2, long a3);
long __seal_sys_faccessat(long a1, long a2, long a3);
long __seal_sys_pselect6_time32(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_ppoll_time32(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_unshare(long a1);
long __seal_sys_set_robust_list(long a1, long a2);
long __seal_sys_get_robust_list(long a1, long a2, long a3);
long __seal_sys_splice(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_ia32_sync_file_range(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_tee(long a1, long a2, long a3, long a4);
long __seal_sys_vmsplice(long a1, long a2, long a3, long a4);
long __seal_sys_move_pages(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_getcpu(long a1, long a2, long a3);
long __seal_sys_epoll_pwait(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_utimensat_time32(long a1, long a2, long a3, long a4);
long __seal_sys_signalfd(long a1, long a2, long a3);
long __seal_sys_timerfd_create(long a1, long a2);
long __seal_sys_eventfd(long a1);
long __seal_sys_ia32_fallocate(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_timerfd_settime32(long a1, long a2, long a3, long a4);
long __seal_sys_timerfd_gettime32(long a1, long a2);
long __seal_sys_signalfd4(long a1, long a2, long a3, long a4);
long __seal_sys_eventfd2(long a1, long a2);
long __seal_sys_epoll_create1(long a1);
long __seal_sys_dup3(long a1, long a2, long a3);
long __seal_sys_pipe2(long a1, long a2);
long __seal_sys_inotify_init1(long a1);
long __seal_sys_preadv(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_pwritev(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_rt_tgsigqueueinfo(long a1, long a2, long a3, long a4);
long __seal_sys_perf_event_open(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_recvmmsg_time32(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_fanotify_init(long a1, long a2);
long __seal_sys_fanotify_mark(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_prlimit64(long a1, long a2, long a3, long a4);
long __seal_sys_name_to_handle_at(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_open_by_handle_at(long a1, long a2, long a3);
long __seal_sys_clock_adjtime32(long a1, long a2);
long __seal_sys_syncfs(long a1);
long __seal_sys_sendmmsg(long a1, long a2, long a3, long a4);
long __seal_sys_setns(long a1, long a2);
long __seal_sys_process_vm_readv(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_process_vm_writev(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_kcmp(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_finit_module(long a1, long a2, long a3);
long __seal_sys_sched_setattr(long a1, long a2, long a3);
long __seal_sys_sched_getattr(long a1, long a2, long a3, long a4);
long __seal_sys_renameat2(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_seccomp(long a1, long a2, long a3);
long __seal_sys_getrandom(long a1, long a2, long a3);
long __seal_sys_memfd_create(long a1, long a2);
long __seal_sys_bpf(long a1, long a2, long a3);
long __seal_sys_execveat(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_socket(long a1, long a2, long a3);
long __seal_sys_socketpair(long a1, long a2, long a3, long a4);
long __seal_sys_bind(long a1, long a2, long a3);
long __seal_sys_connect(long a1, long a2, long a3);
long __seal_sys_listen(long a1, long a2);
long __seal_sys_accept4(long a1, long a2, long a3, long a4);
long __seal_sys_getsockopt(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_setsockopt(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_getsockname(long a1, long a2, long a3);
long __seal_sys_getpeername(long a1, long a2, long a3);
long __seal_sys_sendto(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_sendmsg(long a1, long a2, long a3);
long __seal_sys_recvfrom(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_recvmsg(long a1, long a2, long a3);
long __seal_sys_shutdown(long a1, long a2);
long __seal_sys_userfaultfd(long a1);
long __seal_sys_membarrier(long a1, long a2, long a3);
long __seal_sys_mlock2(long a1, long a2, long a3);
long __seal_sys_copy_file_range(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_preadv2(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_pwritev2(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_pkey_mprotect(long a1, long a2, long a3, long a4);
long __seal_sys_pkey_alloc(long a1, long a2);
long __seal_sys_pkey_free(long a1);
long __seal_sys_statx(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_arch_prctl(long a1, long a2);
long __seal_sys_io_pgetevents_time32(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_rseq(long a1, long a2, long a3, long a4);
long __seal_sys_semget(long a1, long a2, long a3);
long __seal_sys_semctl(long a1, long a2, long a3, long a4);
long __seal_sys_shmget(long a1, long a2, long a3);
long __seal_sys_shmctl(long a1, long a2, long a3);
long __seal_sys_shmat(long a1, long a2, long a3);
long __seal_sys_shmdt(long a1);
long __seal_sys_msgget(long a1, long a2);
long __seal_sys_msgsnd(long a1, long a2, long a3, long a4);
long __seal_sys_msgrcv(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_msgctl(long a1, long a2, long a3);
long __seal_sys_clock_gettime(long a1, long a2);
long __seal_sys_clock_settime(long a1, long a2);
long __seal_sys_clock_adjtime(long a1, long a2);
long __seal_sys_clock_getres(long a1, long a2);
long __seal_sys_clock_nanosleep(long a1, long a2, long a3, long a4);
long __seal_sys_timer_gettime(long a1, long a2);
long __seal_sys_timer_settime(long a1, long a2, long a3, long a4);
long __seal_sys_timerfd_gettime(long a1, long a2);
long __seal_sys_timerfd_settime(long a1, long a2, long a3, long a4);
long __seal_sys_utimensat(long a1, long a2, long a3, long a4);
long __seal_sys_pselect6(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_ppoll(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_io_pgetevents(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_recvmmsg(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_mq_timedsend(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_mq_timedreceive(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_semtimedop(long a1, long a2, long a3, long a4);
long __seal_sys_rt_sigtimedwait(long a1, long a2, long a3, long a4);
long __seal_sys_futex(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_sched_rr_get_interval(long a1, long a2);
long __seal_sys_pidfd_send_signal(long a1, long a2, long a3, long a4);
long __seal_sys_io_uring_setup(long a1, long a2);
long __seal_sys_io_uring_enter(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_io_uring_register(long a1, long a2, long a3, long a4);
long __seal_sys_open_tree(long a1, long a2, long a3);
long __seal_sys_move_mount(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_fsopen(long a1, long a2);
long __seal_sys_fsconfig(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_fsmount(long a1, long a2, long a3);
long __seal_sys_fspick(long a1, long a2, long a3);
long __seal_sys_pidfd_open(long a1, long a2);
long __seal_sys_clone3(long a1, long a2);
long __seal_sys_close_range(long a1, long a2, long a3);
long __seal_sys_openat2(long a1, long a2, long a3, long a4);
long __seal_sys_pidfd_getfd(long a1, long a2, long a3);
long __seal_sys_faccessat2(long a1, long a2, long a3, long a4);
long __seal_sys_process_madvise(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_epoll_pwait2(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_mount_setattr(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_quotactl_fd(long a1, long a2, long a3, long a4);
long __seal_sys_landlock_create_ruleset(long a1, long a2, long a3);
long __seal_sys_landlock_add_rule(long a1, long a2, long a3, long a4);
long __seal_sys_landlock_restrict_self(long a1, long a2);
long __seal_sys_memfd_secret(long a1);
long __seal_sys_process_mrelease(long a1, long a2);
long __seal_sys_futex_waitv(long a1, long a2, long a3, long a4, long a5);
long __seal_sys_set_mempolicy_home_node(long a1, long a2, long a3, long a4);
long __seal_sys_cachestat(long a1, long a2, long a3, long a4);
long __seal_sys_fchmodat2(long a1, long a2, long a3, long a4);
long __seal_sys_map_shadow_stack(long a1, long a2, long a3);
long __seal_sys_futex_wake(long a1, long a2, long a3, long a4);
long __seal_sys_futex_wait(long a1, long a2, long a3, long a4, long a5, long a6);
long __seal_sys_futex_requeue(long a1, long a2, long a3, long a4);
long __seal_sys_statmount(long a1, long a2, long a3, long a4);
long __seal_sys_listmount(long a1, long a2, long a3, long a4);
long __seal_sys_lsm_get_self_attr(long a1, long a2, long a3, long a4);
long __seal_sys_lsm_set_self_attr(long a1, long a2, long a3, long a4);
long __seal_sys_lsm_list_modules(long a1, long a2, long a3);

#define __SEAL_restart_syscall __seal_sys_restart_syscall
#define __SEAL_exit __seal_sys_exit
#define __SEAL_fork __seal_sys_fork
#define __SEAL_read __seal_sys_read
#define __SEAL_write __seal_sys_write
#define __SEAL_open __seal_sys_open
#define __SEAL_close __seal_sys_close
#define __SEAL_waitpid __seal_sys_waitpid
#define __SEAL_creat __seal_sys_creat
#define __SEAL_link __seal_sys_link
#define __SEAL_unlink __seal_sys_unlink
#define __SEAL_execve __seal_sys_execve
#define __SEAL_chdir __seal_sys_chdir
#define __SEAL_time __seal_sys_time32
#define __SEAL_mknod __seal_sys_mknod
#define __SEAL_chmod __seal_sys_chmod
#define __SEAL_lchown __seal_sys_lchown16
#define __SEAL_oldstat __seal_sys_stat
#define __SEAL_lseek __seal_sys_lseek
#define __SEAL_getpid __seal_sys_getpid
#define __SEAL_mount __seal_sys_mount
#define __SEAL_umount __seal_sys_oldumount
#define __SEAL_setuid __seal_sys_setuid16
#define __SEAL_getuid __seal_sys_getuid16
#define __SEAL_stime __seal_sys_stime32
#define __SEAL_ptrace __seal_sys_ptrace
#define __SEAL_alarm __seal_sys_alarm
#define __SEAL_oldfstat __seal_sys_fstat
#define __SEAL_pause __seal_sys_pause
#define __SEAL_utime __seal_sys_utime32
#define __SEAL_access __seal_sys_access
#define __SEAL_nice __seal_sys_nice
#define __SEAL_sync __seal_sys_sync
#define __SEAL_kill __seal_sys_kill
#define __SEAL_rename __seal_sys_rename
#define __SEAL_mkdir __seal_sys_mkdir
#define __SEAL_rmdir __seal_sys_rmdir
#define __SEAL_dup __seal_sys_dup
#define __SEAL_pipe __seal_sys_pipe
#define __SEAL_times __seal_sys_times
#define __SEAL_brk __seal_sys_brk
#define __SEAL_setgid __seal_sys_setgid16
#define __SEAL_getgid __seal_sys_getgid16
#define __SEAL_signal __seal_sys_signal
#define __SEAL_geteuid __seal_sys_geteuid16
#define __SEAL_getegid __seal_sys_getegid16
#define __SEAL_acct __seal_sys_acct
#define __SEAL_umount2 __seal_sys_umount
#define __SEAL_ioctl __seal_sys_ioctl
#define __SEAL_fcntl __seal_sys_fcntl
#define __SEAL_setpgid __seal_sys_setpgid
#define __SEAL_oldolduname __seal_sys_olduname
#define __SEAL_umask __seal_sys_umask
#define __SEAL_chroot __seal_sys_chroot
#define __SEAL_ustat __seal_sys_ustat
#define __SEAL_dup2 __seal_sys_dup2
#define __SEAL_getppid __seal_sys_getppid
#define __SEAL_getpgrp __seal_sys_getpgrp
#define __SEAL_setsid __seal_sys_setsid
#define __SEAL_sigaction __seal_sys_sigaction
#define __SEAL_sgetmask __seal_sys_sgetmask
#define __SEAL_ssetmask __seal_sys_ssetmask
#define __SEAL_setreuid __seal_sys_setreuid16
#define __SEAL_setregid __seal_sys_setregid16
#define __SEAL_sigsuspend __seal_sys_sigsuspend
#define __SEAL_sigpending __seal_sys_sigpending
#define __SEAL_sethostname __seal_sys_sethostname
#define __SEAL_setrlimit __seal_sys_setrlimit
#define __SEAL_getrlimit __seal_sys_old_getrlimit
#define __SEAL_getrusage __seal_sys_getrusage
#define __SEAL_gettimeofday __seal_sys_gettimeofday
#define __SEAL_settimeofday __seal_sys_settimeofday
#define __SEAL_getgroups __seal_sys_getgroups16
#define __SEAL_setgroups __seal_sys_setgroups16
#define __SEAL_select __seal_sys_old_select
#define __SEAL_symlink __seal_sys_symlink
#define __SEAL_oldlstat __seal_sys_lstat
#define __SEAL_readlink __seal_sys_readlink
#define __SEAL_uselib __seal_sys_uselib
#define __SEAL_swapon __seal_sys_swapon
#define __SEAL_reboot __seal_sys_reboot
#define __SEAL_readdir __seal_sys_old_readdir
#define __SEAL_mmap __seal_sys_old_mmap
#define __SEAL_munmap __seal_sys_munmap
#define __SEAL_truncate __seal_sys_truncate
#define __SEAL_ftruncate __seal_sys_ftruncate
#define __SEAL_fchmod __seal_sys_fchmod
#define __SEAL_fchown __seal_sys_fchown16
#define __SEAL_getpriority __seal_sys_getpriority
#define __SEAL_setpriority __seal_sys_setpriority
#define __SEAL_statfs __seal_sys_statfs
#define __SEAL_fstatfs __seal_sys_fstatfs
#define __SEAL_ioperm __seal_sys_ioperm
#define __SEAL_socketcall __seal_sys_socketcall
#define __SEAL_syslog __seal_sys_syslog
#define __SEAL_setitimer __seal_sys_setitimer
#define __SEAL_getitimer __seal_sys_getitimer
#define __SEAL_stat __seal_sys_newstat
#define __SEAL_lstat __seal_sys_newlstat
#define __SEAL_fstat __seal_sys_newfstat
#define __SEAL_olduname __seal_sys_uname
#define __SEAL_iopl __seal_sys_iopl
#define __SEAL_vhangup __seal_sys_vhangup
#define __SEAL_wait4 __seal_sys_wait4
#define __SEAL_swapoff __seal_sys_swapoff
#define __SEAL_sysinfo __seal_sys_sysinfo
#define __SEAL_ipc __seal_sys_ipc
#define __SEAL_fsync __seal_sys_fsync
#define __SEAL_sigreturn __seal_sys_sigreturn
#define __SEAL_clone __seal_sys_clone
#define __SEAL_setdomainname __seal_sys_setdomainname
#define __SEAL_uname __seal_sys_newuname
#define __SEAL_modify_ldt __seal_sys_modify_ldt
#define __SEAL_adjtimex __seal_sys_adjtimex_time32
#define __SEAL_mprotect __seal_sys_mprotect
#define __SEAL_sigprocmask __seal_sys_sigprocmask
#define __SEAL_init_module __seal_sys_init_module
#define __SEAL_delete_module __seal_sys_delete_module
#define __SEAL_quotactl __seal_sys_quotactl
#define __SEAL_getpgid __seal_sys_getpgid
#define __SEAL_fchdir __seal_sys_fchdir
#define __SEAL_sysfs __seal_sys_sysfs
#define __SEAL_personality __seal_sys_personality
#define __SEAL_setfsuid __seal_sys_setfsuid16
#define __SEAL_setfsgid __seal_sys_setfsgid16
#define __SEAL__llseek __seal_sys_llseek
#define __SEAL_getdents __seal_sys_getdents
#define __SEAL__newselect __seal_sys_select
#define __SEAL_flock __seal_sys_flock
#define __SEAL_msync __seal_sys_msync
#define __SEAL_readv __seal_sys_readv
#define __SEAL_writev __seal_sys_writev
#define __SEAL_getsid __seal_sys_getsid
#define __SEAL_fdatasync __seal_sys_fdatasync
#define __SEAL_mlock __seal_sys_mlock
#define __SEAL_munlock __seal_sys_munlock
#define __SEAL_mlockall __seal_sys_mlockall
#define __SEAL_munlockall __seal_sys_munlockall
#define __SEAL_sched_setparam __seal_sys_sched_setparam
#define __SEAL_sched_getparam __seal_sys_sched_getparam
#define __SEAL_sched_setscheduler __seal_sys_sched_setscheduler
#define __SEAL_sched_getscheduler __seal_sys_sched_getscheduler
#define __SEAL_sched_yield __seal_sys_sched_yield
#define __SEAL_sched_get_priority_max __seal_sys_sched_get_priority_max
#define __SEAL_sched_get_priority_min __seal_sys_sched_get_priority_min
#define __SEAL_sched_rr_get_interval __seal_sys_sched_rr_get_interval_time32
#define __SEAL_nanosleep __seal_sys_nanosleep_time32
#define __SEAL_mremap __seal_sys_mremap
#define __SEAL_setresuid __seal_sys_setresuid16
#define __SEAL_getresuid __seal_sys_getresuid16
#define __SEAL_poll __seal_sys_poll
#define __SEAL_setresgid __seal_sys_setresgid16
#define __SEAL_getresgid __seal_sys_getresgid16
#define __SEAL_prctl __seal_sys_prctl
#define __SEAL_rt_sigreturn __seal_sys_rt_sigreturn
#define __SEAL_rt_sigaction __seal_sys_rt_sigaction
#define __SEAL_rt_sigprocmask __seal_sys_rt_sigprocmask
#define __SEAL_rt_sigpending __seal_sys_rt_sigpending
#define __SEAL_rt_sigtimedwait __seal_sys_rt_sigtimedwait_time32
#define __SEAL_rt_sigqueueinfo __seal_sys_rt_sigqueueinfo
#define __SEAL_rt_sigsuspend __seal_sys_rt_sigsuspend
#define __SEAL_pread64 __seal_sys_ia32_pread64
#define __SEAL_pwrite64 __seal_sys_ia32_pwrite64
#define __SEAL_chown __seal_sys_chown16
#define __SEAL_getcwd __seal_sys_getcwd
#define __SEAL_capget __seal_sys_capget
#define __SEAL_capset __seal_sys_capset
#define __SEAL_sigaltstack __seal_sys_sigaltstack
#define __SEAL_sendfile __seal_sys_sendfile
#define __SEAL_vfork __seal_sys_vfork
#define __SEAL_ugetrlimit __seal_sys_getrlimit
#define __SEAL_mmap2 __seal_sys_mmap_pgoff
#define __SEAL_truncate64 __seal_sys_ia32_truncate64
#define __SEAL_ftruncate64 __seal_sys_ia32_ftruncate64
#define __SEAL_stat64 __seal_sys_stat64
#define __SEAL_lstat64 __seal_sys_lstat64
#define __SEAL_fstat64 __seal_sys_fstat64
#define __SEAL_lchown32 __seal_sys_lchown
#define __SEAL_getuid32 __seal_sys_getuid
#define __SEAL_getgid32 __seal_sys_getgid
#define __SEAL_geteuid32 __seal_sys_geteuid
#define __SEAL_getegid32 __seal_sys_getegid
#define __SEAL_setreuid32 __seal_sys_setreuid
#define __SEAL_setregid32 __seal_sys_setregid
#define __SEAL_getgroups32 __seal_sys_getgroups
#define __SEAL_setgroups32 __seal_sys_setgroups
#define __SEAL_fchown32 __seal_sys_fchown
#define __SEAL_setresuid32 __seal_sys_setresuid
#define __SEAL_getresuid32 __seal_sys_getresuid
#define __SEAL_setresgid32 __seal_sys_setresgid
#define __SEAL_getresgid32 __seal_sys_getresgid
#define __SEAL_chown32 __seal_sys_chown
#define __SEAL_setuid32 __seal_sys_setuid
#define __SEAL_setgid32 __seal_sys_setgid
#define __SEAL_setfsuid32 __seal_sys_setfsuid
#define __SEAL_setfsgid32 __seal_sys_setfsgid
#define __SEAL_pivot_root __seal_sys_pivot_root
#define __SEAL_mincore __seal_sys_mincore
#define __SEAL_madvise __seal_sys_madvise
#define __SEAL_getdents64 __seal_sys_getdents64
#define __SEAL_fcntl64 __seal_sys_fcntl64
#define __SEAL_gettid __seal_sys_gettid
#define __SEAL_readahead __seal_sys_ia32_readahead
#define __SEAL_setxattr __seal_sys_setxattr
#define __SEAL_lsetxattr __seal_sys_lsetxattr
#define __SEAL_fsetxattr __seal_sys_fsetxattr
#define __SEAL_getxattr __seal_sys_getxattr
#define __SEAL_lgetxattr __seal_sys_lgetxattr
#define __SEAL_fgetxattr __seal_sys_fgetxattr
#define __SEAL_listxattr __seal_sys_listxattr
#define __SEAL_llistxattr __seal_sys_llistxattr
#define __SEAL_flistxattr __seal_sys_flistxattr
#define __SEAL_removexattr __seal_sys_removexattr
#define __SEAL_lremovexattr __seal_sys_lremovexattr
#define __SEAL_fremovexattr __seal_sys_fremovexattr
#define __SEAL_tkill __seal_sys_tkill
#define __SEAL_sendfile64 __seal_sys_sendfile64
#define __SEAL_futex __seal_sys_futex_time32
#define __SEAL_sched_setaffinity __seal_sys_sched_setaffinity
#define __SEAL_sched_getaffinity __seal_sys_sched_getaffinity
#define __SEAL_io_setup __seal_sys_io_setup
#define __SEAL_io_destroy __seal_sys_io_destroy
#define __SEAL_io_getevents __seal_sys_io_getevents_time32
#define __SEAL_io_submit __seal_sys_io_submit
#define __SEAL_io_cancel __seal_sys_io_cancel
#define __SEAL_fadvise64 __seal_sys_ia32_fadvise64
#define __SEAL_exit_group __seal_sys_exit_group
#define __SEAL_epoll_create __seal_sys_epoll_create
#define __SEAL_epoll_ctl __seal_sys_epoll_ctl
#define __SEAL_epoll_wait __seal_sys_epoll_wait
#define __SEAL_remap_file_pages __seal_sys_remap_file_pages
#define __SEAL_set_tid_address __seal_sys_set_tid_address
#define __SEAL_timer_create __seal_sys_timer_create
#define __SEAL_timer_settime __seal_sys_timer_settime32
#define __SEAL_timer_gettime __seal_sys_timer_gettime32
#define __SEAL_timer_getoverrun __seal_sys_timer_getoverrun
#define __SEAL_timer_delete __seal_sys_timer_delete
#define __SEAL_clock_settime __seal_sys_clock_settime32
#define __SEAL_clock_gettime __seal_sys_clock_gettime32
#define __SEAL_clock_getres __seal_sys_clock_getres_time32
#define __SEAL_clock_nanosleep __seal_sys_clock_nanosleep_time32
#define __SEAL_statfs64 __seal_sys_statfs64
#define __SEAL_fstatfs64 __seal_sys_fstatfs64
#define __SEAL_tgkill __seal_sys_tgkill
#define __SEAL_utimes __seal_sys_utimes_time32
#define __SEAL_fadvise64_64 __seal_sys_ia32_fadvise64_64
#define __SEAL_mbind __seal_sys_mbind
#define __SEAL_get_mempolicy __seal_sys_get_mempolicy
#define __SEAL_set_mempolicy __seal_sys_set_mempolicy
#define __SEAL_mq_open __seal_sys_mq_open
#define __SEAL_mq_unlink __seal_sys_mq_unlink
#define __SEAL_mq_timedsend __seal_sys_mq_timedsend_time32
#define __SEAL_mq_timedreceive __seal_sys_mq_timedreceive_time32
#define __SEAL_mq_notify __seal_sys_mq_notify
#define __SEAL_mq_getsetattr __seal_sys_mq_getsetattr
#define __SEAL_kexec_load __seal_sys_kexec_load
#define __SEAL_waitid __seal_sys_waitid
#define __SEAL_add_key __seal_sys_add_key
#define __SEAL_request_key __seal_sys_request_key
#define __SEAL_keyctl __seal_sys_keyctl
#define __SEAL_ioprio_set __seal_sys_ioprio_set
#define __SEAL_ioprio_get __seal_sys_ioprio_get
#define __SEAL_inotify_init __seal_sys_inotify_init
#define __SEAL_inotify_add_watch __seal_sys_inotify_add_watch
#define __SEAL_inotify_rm_watch __seal_sys_inotify_rm_watch
#define __SEAL_migrate_pages __seal_sys_migrate_pages
#define __SEAL_openat __seal_sys_openat
#define __SEAL_mkdirat __seal_sys_mkdirat
#define __SEAL_mknodat __seal_sys_mknodat
#define __SEAL_fchownat __seal_sys_fchownat
#define __SEAL_futimesat __seal_sys_futimesat_time32
#define __SEAL_fstatat64 __seal_sys_fstatat64
#define __SEAL_unlinkat __seal_sys_unlinkat
#define __SEAL_renameat __seal_sys_renameat
#define __SEAL_linkat __seal_sys_linkat
#define __SEAL_symlinkat __seal_sys_symlinkat
#define __SEAL_readlinkat __seal_sys_readlinkat
#define __SEAL_fchmodat __seal_sys_fchmodat
#define __SEAL_faccessat __seal_sys_faccessat
#define __SEAL_pselect6 __seal_sys_pselect6_time32
#define __SEAL_ppoll __seal_sys_ppoll_time32
#define __SEAL_unshare __seal_sys_unshare
#define __SEAL_set_robust_list __seal_sys_set_robust_list
#define __SEAL_get_robust_list __seal_sys_get_robust_list
#define __SEAL_splice __seal_sys_splice
#define __SEAL_sync_file_range __seal_sys_ia32_sync_file_range
#define __SEAL_tee __seal_sys_tee
#define __SEAL_vmsplice __seal_sys_vmsplice
#define __SEAL_move_pages __seal_sys_move_pages
#define __SEAL_getcpu __seal_sys_getcpu
#define __SEAL_epoll_pwait __seal_sys_epoll_pwait
#define __SEAL_utimensat __seal_sys_utimensat_time32
#define __SEAL_signalfd __seal_sys_signalfd
#define __SEAL_timerfd_create __seal_sys_timerfd_create
#define __SEAL_eventfd __seal_sys_eventfd
#define __SEAL_fallocate __seal_sys_ia32_fallocate
#define __SEAL_timerfd_settime __seal_sys_timerfd_settime32
#define __SEAL_timerfd_gettime __seal_sys_timerfd_gettime32
#define __SEAL_signalfd4 __seal_sys_signalfd4
#define __SEAL_eventfd2 __seal_sys_eventfd2
#define __SEAL_epoll_create1 __seal_sys_epoll_create1
#define __SEAL_dup3 __seal_sys_dup3
#define __SEAL_pipe2 __seal_sys_pipe2
#define __SEAL_inotify_init1 __seal_sys_inotify_init1
#define __SEAL_preadv __seal_sys_preadv
#define __SEAL_pwritev __seal_sys_pwritev
#define __SEAL_rt_tgsigqueueinfo __seal_sys_rt_tgsigqueueinfo
#define __SEAL_perf_event_open __seal_sys_perf_event_open
#define __SEAL_recvmmsg __seal_sys_recvmmsg_time32
#define __SEAL_fanotify_init __seal_sys_fanotify_init
#define __SEAL_fanotify_mark __seal_sys_fanotify_mark
#define __SEAL_prlimit64 __seal_sys_prlimit64
#define __SEAL_name_to_handle_at __seal_sys_name_to_handle_at
#define __SEAL_open_by_handle_at __seal_sys_open_by_handle_at
#define __SEAL_clock_adjtime __seal_sys_clock_adjtime32
#define __SEAL_syncfs __seal_sys_syncfs
#define __SEAL_sendmmsg __seal_sys_sendmmsg
#define __SEAL_setns __seal_sys_setns
#define __SEAL_process_vm_readv __seal_sys_process_vm_readv
#define __SEAL_process_vm_writev __seal_sys_process_vm_writev
#define __SEAL_kcmp __seal_sys_kcmp
#define __SEAL_finit_module __seal_sys_finit_module
#define __SEAL_sched_setattr __seal_sys_sched_setattr
#define __SEAL_sched_getattr __seal_sys_sched_getattr
#define __SEAL_renameat2 __seal_sys_renameat2
#define __SEAL_seccomp __seal_sys_seccomp
#define __SEAL_getrandom __seal_sys_getrandom
#define __SEAL_memfd_create __seal_sys_memfd_create
#define __SEAL_bpf __seal_sys_bpf
#define __SEAL_execveat __seal_sys_execveat
#define __SEAL_socket __seal_sys_socket
#define __SEAL_socketpair __seal_sys_socketpair
#define __SEAL_bind __seal_sys_bind
#define __SEAL_connect __seal_sys_connect
#define __SEAL_listen __seal_sys_listen
#define __SEAL_accept4 __seal_sys_accept4
#define __SEAL_getsockopt __seal_sys_getsockopt
#define __SEAL_setsockopt __seal_sys_setsockopt
#define __SEAL_getsockname __seal_sys_getsockname
#define __SEAL_getpeername __seal_sys_getpeername
#define __SEAL_sendto __seal_sys_sendto
#define __SEAL_sendmsg __seal_sys_sendmsg
#define __SEAL_recvfrom __seal_sys_recvfrom
#define __SEAL_recvmsg __seal_sys_recvmsg
#define __SEAL_shutdown __seal_sys_shutdown
#define __SEAL_userfaultfd __seal_sys_userfaultfd
#define __SEAL_membarrier __seal_sys_membarrier
#define __SEAL_mlock2 __seal_sys_mlock2
#define __SEAL_copy_file_range __seal_sys_copy_file_range
#define __SEAL_preadv2 __seal_sys_preadv2
#define __SEAL_pwritev2 __seal_sys_pwritev2
#define __SEAL_pkey_mprotect __seal_sys_pkey_mprotect
#define __SEAL_pkey_alloc __seal_sys_pkey_alloc
#define __SEAL_pkey_free __seal_sys_pkey_free
#define __SEAL_statx __seal_sys_statx
#define __SEAL_arch_prctl __seal_sys_arch_prctl
#define __SEAL_io_pgetevents __seal_sys_io_pgetevents_time32
#define __SEAL_rseq __seal_sys_rseq
#define __SEAL_semget __seal_sys_semget
#define __SEAL_semctl __seal_sys_semctl
#define __SEAL_shmget __seal_sys_shmget
#define __SEAL_shmctl __seal_sys_shmctl
#define __SEAL_shmat __seal_sys_shmat
#define __SEAL_shmdt __seal_sys_shmdt
#define __SEAL_msgget __seal_sys_msgget
#define __SEAL_msgsnd __seal_sys_msgsnd
#define __SEAL_msgrcv __seal_sys_msgrcv
#define __SEAL_msgctl __seal_sys_msgctl
#define __SEAL_clock_gettime64 __seal_sys_clock_gettime
#define __SEAL_clock_settime64 __seal_sys_clock_settime
#define __SEAL_clock_adjtime64 __seal_sys_clock_adjtime
#define __SEAL_clock_getres_time64 __seal_sys_clock_getres
#define __SEAL_clock_nanosleep_time64 __seal_sys_clock_nanosleep
#define __SEAL_timer_gettime64 __seal_sys_timer_gettime
#define __SEAL_timer_settime64 __seal_sys_timer_settime
#define __SEAL_timerfd_gettime64 __seal_sys_timerfd_gettime
#define __SEAL_timerfd_settime64 __seal_sys_timerfd_settime
#define __SEAL_utimensat_time64 __seal_sys_utimensat
#define __SEAL_pselect6_time64 __seal_sys_pselect6
#define __SEAL_ppoll_time64 __seal_sys_ppoll
#define __SEAL_io_pgetevents_time64 __seal_sys_io_pgetevents
#define __SEAL_recvmmsg_time64 __seal_sys_recvmmsg
#define __SEAL_mq_timedsend_time64 __seal_sys_mq_timedsend
#define __SEAL_mq_timedreceive_time64 __seal_sys_mq_timedreceive
#define __SEAL_semtimedop_time64 __seal_sys_semtimedop
#define __SEAL_rt_sigtimedwait_time64 __seal_sys_rt_sigtimedwait
#define __SEAL_futex_time64 __seal_sys_futex
#define __SEAL_sched_rr_get_interval_time64 __seal_sys_sched_rr_get_interval
#define __SEAL_pidfd_send_signal __seal_sys_pidfd_send_signal
#define __SEAL_io_uring_setup __seal_sys_io_uring_setup
#define __SEAL_io_uring_enter __seal_sys_io_uring_enter
#define __SEAL_io_uring_register __seal_sys_io_uring_register
#define __SEAL_open_tree __seal_sys_open_tree
#define __SEAL_move_mount __seal_sys_move_mount
#define __SEAL_fsopen __seal_sys_fsopen
#define __SEAL_fsconfig __seal_sys_fsconfig
#define __SEAL_fsmount __seal_sys_fsmount
#define __SEAL_fspick __seal_sys_fspick
#define __SEAL_pidfd_open __seal_sys_pidfd_open
#define __SEAL_clone3 __seal_sys_clone3
#define __SEAL_close_range __seal_sys_close_range
#define __SEAL_openat2 __seal_sys_openat2
#define __SEAL_pidfd_getfd __seal_sys_pidfd_getfd
#define __SEAL_faccessat2 __seal_sys_faccessat2
#define __SEAL_process_madvise __seal_sys_process_madvise
#define __SEAL_epoll_pwait2 __seal_sys_epoll_pwait2
#define __SEAL_mount_setattr __seal_sys_mount_setattr
#define __SEAL_quotactl_fd __seal_sys_quotactl_fd
#define __SEAL_landlock_create_ruleset __seal_sys_landlock_create_ruleset
#define __SEAL_landlock_add_rule __seal_sys_landlock_add_rule
#define __SEAL_landlock_restrict_self __seal_sys_landlock_restrict_self
#define __SEAL_memfd_secret __seal_sys_memfd_secret
#define __SEAL_process_mrelease __seal_sys_process_mrelease
#define __SEAL_futex_waitv __seal_sys_futex_waitv
#define __SEAL_set_mempolicy_home_node __seal_sys_set_mempolicy_home_node
#define __SEAL_cachestat __seal_sys_cachestat
#define __SEAL_fchmodat2 __seal_sys_fchmodat2
#define __SEAL_map_shadow_stack __seal_sys_map_shadow_stack
#define __SEAL_futex_wake __seal_sys_futex_wake
#define __SEAL_futex_wait __seal_sys_futex_wait
#define __SEAL_futex_requeue __seal_sys_futex_requeue
#define __SEAL_statmount __seal_sys_statmount
#define __SEAL_listmount __seal_sys_listmount
#define __SEAL_lsm_get_self_attr __seal_sys_lsm_get_self_attr
#define __SEAL_lsm_set_self_attr __seal_sys_lsm_set_self_attr
#define __SEAL_lsm_list_modules __seal_sys_lsm_list_modules

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_ARCH_ARCH_SYSCALL_H */
