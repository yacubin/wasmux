/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_PWD_H
#define _WA_LIBC_PWD_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct passwd {
  char* pw_name;
  char* pw_passwd;
  uid_t pw_uid;
  gid_t pw_gid;
  time_t pw_change;
  char* pw_class;
  char* pw_gecos;
  char* pw_dir;
  char* pw_shell;
  time_t pw_expire;
};

struct passwd* getpwuid(uid_t uid);
struct passwd* getpwnam(const char* name);
int getpwuid_r(uid_t uid, struct passwd* pwd, char* buf, size_t len, struct passwd** result);
int getpwnam_r(const char* name, struct passwd* pwd, char* buf, size_t len, struct passwd** result);
struct passwd* getpwent(void);
void setpwent(void);
void endpwent(void);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_PWD_H */
