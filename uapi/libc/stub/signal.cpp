/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "signal.h"

#include <kernel/assert.h>
#include <errno.h>

sighandler_t signal(int signum, sighandler_t handler)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int sigprocmask(int how, const sigset_t* set, sigset_t* oldset)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigsuspend(const sigset_t* set)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigemptyset(sigset_t* set)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigfillset(sigset_t* set)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigaddset(sigset_t* set, int signum)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigdelset(sigset_t* set, int signum)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigismember(const sigset_t* set, int signum)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigwait(const sigset_t* set, int* signum)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int raise(int signum)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int killpg(int pidgrp, int signum)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int kill(pid_t pid, int sig)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int pthread_sigmask(int how, const sigset_t* set, sigset_t* oldset)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int sigaltstack(const stack_t* stack, stack_t* old_stack)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
