/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_UTSNAME_H
#define _WA_LIBC_SYS_UTSNAME_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define __UTSNAME_LEN 64

struct utsname {
	char sysname[__UTSNAME_LEN + 1];
	char nodename[__UTSNAME_LEN + 1];
	char release[__UTSNAME_LEN + 1];
	char version[__UTSNAME_LEN + 1];
	char machine[__UTSNAME_LEN + 1];
	char domainname[__UTSNAME_LEN + 1];
};

int uname(struct utsname* buf);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_UTSNAME_H */
