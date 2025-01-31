/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SHADOW_H
#define _SHADOW_H

#ifdef __cplusplus
extern "C" {
#endif

struct spwd {
  char* sp_namp;
  char* sp_pwdp;
  long sp_lstchg;
  long sp_min;
  long sp_max;
  long sp_warn;
  long sp_inact;
  long sp_expire;
  unsigned long sp_flag;
};

struct spwd* getspent(void);

#ifdef __cplusplus
}
#endif

#endif /* _SHADOW_H */
