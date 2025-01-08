/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_SIGNAL_H
#define _WA_KERNEL_SIGNAL_H

#define __BITS_PER_ULONG (sizeof(unsigned long) * 8)

#define _NSIG 64
#define _NSIG_WORDS (_NSIG / __BITS_PER_ULONG)

typedef struct sigset_t {
  unsigned long sig[_NSIG_WORDS];
} sigset_t;

#define sigmask(signum) (1UL << ((signum) - 1))

#define SIG_BLOCK    0
#define SIG_UNBLOCK  1
#define SIG_SETMASK  2

#endif /* _WA_KERNEL_SIGNAL_H */
