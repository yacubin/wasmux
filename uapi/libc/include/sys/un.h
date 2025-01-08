/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_UN_H
#define _WA_LIBC_SYS_UN_H

#include <wasmux/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UNIX_PATH_MAX	108

struct sockaddr_un {
  sa_family_t sun_family;
  char sun_path[UNIX_PATH_MAX];
};

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_UN_H */
