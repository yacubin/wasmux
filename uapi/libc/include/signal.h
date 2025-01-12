/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SIGNAL_H
#define _WA_LIBC_SIGNAL_H

#include <wasmux/types.h>
#include <wasmux/signal.h>
#include <setjmp.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NSIG _NSIG

#define SA_SIGINFO   0x00000004
#define SA_ONSTACK   0x08000000
#define SA_RESTART   0x10000000
#define SA_RESETHAND 0x80000000

typedef int sig_atomic_t;

typedef struct {
  int si_signo;
  int si_errno;
  int si_code;
  pid_t si_pid;
  uid_t si_uid;
  void* si_addr;
  int si_status;

  long si_band;
  int si_fd;

  union {
    int sival_int;
    void* sival_ptr;
  } si_value;

} siginfo_t;

typedef void (*sighandler_t) (int);

#define SIG_ERR ((sighandler_t)-1)
#define SIG_DFL ((sighandler_t)0)
#define SIG_IGN ((sighandler_t)1)

struct sigaction {
  union {
    sighandler_t sa_handler;
    void (*sa_sigaction) (int, siginfo_t*, void*);
  } _u;
  sigset_t sa_mask;
  unsigned long sa_flags;
  void (*sa_restorer) (void);
};

#define sa_handler    _u.sa_handler
#define sa_sigaction  _u.sa_sigaction

sighandler_t signal(int signum, sighandler_t handler);
int sigprocmask(int how, const sigset_t* set, sigset_t* oldset);
int sigsuspend(const sigset_t* set);
int sigemptyset(sigset_t* set);
int sigfillset(sigset_t* set);
int sigaddset(sigset_t* set, int signum);
int sigdelset(sigset_t* set, int signum);
int sigismember(const sigset_t* set, int signum);
int sigwait(const sigset_t* set, int* signum);
int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact);
int raise(int signum);
int killpg(int pidgrp, int signum);

int kill(pid_t pid, int sig);

int pthread_sigmask(int how, const sigset_t* set, sigset_t* oldset);

#define SS_ONSTACK 1
#define SS_DISABLE 2

typedef struct {
  void*  ss_sp;
  int    ss_flags;
  size_t ss_size;
} stack_t;

int sigaltstack(const stack_t* stack, stack_t* old_stack);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SIGNAL_H */
