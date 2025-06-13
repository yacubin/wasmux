/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SETJMP_H
#define _SETJMP_H

#include <signal.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef long jmp_buf;

struct __sigjmp_buf {
  jmp_buf __jmpbuf;
  int __mask_was_saved;
  sigset_t __saved_mask;
};

typedef struct __sigjmp_buf sigjmp_buf[1];

int _setjmp(jmp_buf env);
void _longjmp(jmp_buf env, int val) __attribute__((noreturn));

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val) __attribute__((noreturn));
void siglongjmp(sigjmp_buf env, int val) __attribute__((noreturn));
int sigsetjmp(sigjmp_buf env, int savesigs);

#ifdef __cplusplus
}
#endif

#endif /* _SETJMP_H */
