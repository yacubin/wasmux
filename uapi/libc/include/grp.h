/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_GRP_H
#define _WA_LIBC_GRP_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct group {
  char* gr_name;
  char* gr_passwd;
  gid_t gr_gid;
  char** gr_mem;
};

struct group* getgrgid(gid_t gid);
struct group* getgrnam(const char* name);
int getgrnam_r(const char* name, struct group* grp, char* buf, size_t len, struct group** result);

struct group* getgrent(void);
void setgrent(void);
void endgrent(void);

int initgroups(const char* user, gid_t group);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_GRP_H */
