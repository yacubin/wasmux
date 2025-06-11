/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SOCKET_H
#define _WASMUX_SOCKET_H

#define AF_UNSPEC 0
#define AF_UNIX   1
#define AF_LOCAL  1
#define AF_INET   2
#define AF_INET6  10
#define AF_PACKET 17

#define PF_UNSPEC AF_UNSPEC
#define PF_UNIX   AF_UNIX
#define PF_LOCAL  AF_LOCAL
#define PF_INET   AF_INET
#define PF_INET6  AF_INET6
#define PF_PACKET AF_PACKET

#define SOMAXCONN 128

#define MSG_PEEK     0x00000002
#define MSG_TRUNC    0x00000020
#define MSG_NOSIGNAL 0x00004000

#define __SS_MAXSIZE 128

#define MSG_CMSG_CLOEXEC 0x40000000

typedef unsigned short in_port_t;
typedef unsigned short sa_family_t;
typedef unsigned int socklen_t;

struct sockaddr {
  sa_family_t sa_family;
  char sa_data[14];
};

struct sockaddr_storage {
  union {
    struct {
      sa_family_t ss_family; /* address family */
      char __data[__SS_MAXSIZE - sizeof(sa_family_t)];
    };
    void* __align;
  };
};

#endif /* _WASMUX_SOCKET_H */
