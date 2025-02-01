/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _UTMP_H
#define _UTMP_H

#include <wasmux/types.h>
#include <wasmux/time.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UT_LINESIZE 32
#define UT_NAMESIZE 32
#define UT_HOSTSIZE 256

struct exit_status {
  short e_termination;
  short e_exit;
};

struct utmp {
  short ut_type;
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

void updwtmp(const char* file, const struct utmp* utmp);
struct utmp* pututline(const struct utmp* utmp);
void setutent(void);
void endutent(void);

#define EMPTY         0
#define RUN_LVL       1
#define BOOT_TIME     2
#define NEW_TIME      3
#define OLD_TIME      4
#define INIT_PROCESS  5
#define LOGIN_PROCESS 6
#define USER_PROCESS  7
#define DEAD_PROCESS  8

#ifdef __cplusplus
}
#endif

#endif /* _UTMP_H */
