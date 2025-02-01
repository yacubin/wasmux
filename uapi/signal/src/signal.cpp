/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <signal.h>
#include <errno.h>
#include <assert.h>

sighandler_t signal(int signum, sighandler_t handler)
{
  assert(0);
  errno = ENOSYS;
  return nullptr;
}

int sigprocmask(int how, const sigset_t* set, sigset_t* oldset)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigsuspend(const sigset_t* set)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigfillset(sigset_t* set)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigaddset(sigset_t* set, int signum)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigdelset(sigset_t* set, int signum)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigismember(const sigset_t* set, int signum)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigwait(const sigset_t* set, int* signum)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigaction(int signum, const struct sigaction* act, struct sigaction* oldact)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int siginterrupt(int signum, int interrupt)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int raise(int signum)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int killpg(int pidgrp, int signum)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int kill(pid_t pid, int sig)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int pthread_sigmask(int how, const sigset_t* set, sigset_t* oldset)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int sigaltstack(const stack_t* stack, stack_t* old_stack)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
