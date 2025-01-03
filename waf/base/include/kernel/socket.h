/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_SOCKET_H
#define _WA_KERNEL_SOCKET_H

#define __SS_MAXSIZE 128

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

#endif /* _WA_KERNEL_SOCKET_H */
