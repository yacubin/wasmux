/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYS_SOCKET_H
#define _WA_LIBC_SYS_SOCKET_H

#include <wasmux/types.h>
#include <wasmux/socket.h>
#include <sys/uio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MSG_PEEK     0x00000002
#define MSG_NOSIGNAL 0x00004000

#define SOL_SOCKET 1

#define SO_DEBUG      1
#define SO_REUSEADDR  2
#define SO_TYPE       3
#define SO_ERROR      4
#define SO_DONTROUTE  5
#define SO_BROADCAST  6
#define SO_SNDBUF     7
#define SO_RCVBUF     8
#define SO_KEEPALIVE  9

#define SCM_RIGHTS 0x01

enum sock_type {
  SOCK_STREAM    = 1,
  SOCK_DGRAM     = 2,
  SOCK_RAW       = 3,
  SOCK_RDM       = 4,
  SOCK_SEQPACKET = 5,
  SOCK_DCCP      = 6,
  SOCK_PACKET    = 10,
  SOCK_CLOEXEC   = 02000000,
  SOCK_NONBLOCK  = 00004000,
};

/* shutdown */
enum {
  SHUT_RD,
  SHUT_WR,
  SHUT_RDWR,
};

struct cmsghdr {
  socklen_t  cmsg_len;    // Length of the control message, including header
  int        cmsg_level;  // Protocol level (e.g., SOL_SOCKET)
  int        cmsg_type;   // Type of the control message (e.g., SCM_RIGHTS)
};

struct msghdr {
  void*         msg_name;       // Optional address
  socklen_t     msg_namelen;    // Size of the address
  struct iovec* msg_iov;        // Scatter/gather array
  int           msg_iovlen;     // Number of elements in msg_iov
  void*         msg_control;    // Ancillary data (control messages)
  size_t        msg_controllen; // Ancillary data buffer length
  int           msg_flags;      // Flags on received message
};

#define CMSG_DATA(cmsg) ((unsigned char *) ((struct cmsghdr *) (cmsg) + 1))
#define CMSG_LEN(len) (sizeof(struct cmsghdr) + (len))

int socket(int domain, int type, int protocol);
int connect(int sock, const struct sockaddr* addr, socklen_t addrlen);
int bind(int sock, const struct sockaddr* addr, socklen_t addrlen);
int listen(int sock, int backlog);
int accept(int sock, struct sockaddr* addr, socklen_t* addrlen);
ssize_t recv(int sock, void* buf, size_t len, int flags);
ssize_t send(int sock, const void* buf, size_t len, int flags);
ssize_t recvfrom(int sock, void* data, size_t size, int flags, struct sockaddr* addr, socklen_t* addrlen);
ssize_t sendto(int sock, const void* data, size_t size, int flags, const struct sockaddr* addr, socklen_t addrlen);
ssize_t recvmsg(int sock, struct msghdr* message, int flags);
ssize_t sendmsg(int sock, const struct msghdr* message, int flags);
int getpeername(int sock, struct sockaddr* addr, socklen_t* addrlen);
int getsockname(int sock, struct sockaddr* addr, socklen_t* addrlen);
int shutdown(int sock, int how);
int getsockopt(int sock, int level, int name, void* data, socklen_t* size);
int setsockopt(int sock, int level, int name, const void* data, socklen_t size);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_SYS_SOCKET_H */
