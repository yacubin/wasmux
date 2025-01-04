/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_UTMPX_H
#define _WA_LIBC_UTMPX_H

#include <utmp.h>

#ifdef __cplusplus
extern "C" {
#endif

struct utmpx {
  short int ut_type;
  pid_t ut_pid;
  char ut_line[UT_LINESIZE];
  char ut_id[4];
  char ut_user[UT_NAMESIZE];
  char ut_host[UT_HOSTSIZE];
  struct exit_status ut_exit;
  long int ut_session;
  struct timeval ut_tv;
  int32_t ut_addr_v6[4];
  char __unused[20];
};

struct utmpx* getutxent(void);
void setutxent(void);
void endutxent(void);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_UTMPX_H */
