/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <ucontext.h>
#include <errno.h>
#include <stdlib.h>

int getcontext(ucontext_t* ucp)
{
  abort();
  errno = ENOSYS;
  return -1;
}

int setcontext(const ucontext_t* ucp)
{
  abort();
  errno = ENOSYS;
  return -1;
}

void makecontext(struct ucontext* ucp, void (*func)(void), int argc, ...)
{
  abort();
}
