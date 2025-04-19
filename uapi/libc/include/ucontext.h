/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _UCONTEXT_H
#define _UCONTEXT_H

#include <sys/types.h>
#include <signal.h> // For stack_t

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ucontext {
  unsigned long uc_flags;
  struct ucontext* uc_link;
  stack_t uc_stack;
} ucontext_t;

int getcontext(ucontext_t* ucp);
int setcontext(const ucontext_t* ucp);

void makecontext(struct ucontext*, void (*func)(void), int argc, ...);

#ifdef __cplusplus
}
#endif

#endif /* _UCONTEXT_H */
