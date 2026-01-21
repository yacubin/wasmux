/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_NET_NET1_H
#define _WASMUX_NET_NET1_H

#include <wasmux/types.h>
#include <wasmux/export.h>
#include <wasmux/platform.h>
#include <wasmux/socket.h>

__EXPORT int net1_socket(int family, int type, int protocol);
__EXPORT int net1_close(int fd);
__EXPORT int net1_bind(int fd, struct sockaddr* addr, int addrlen);
__EXPORT int net1_listen(int fd, int backlog);
__EXPORT int net1_recv(int fd, void* buf, size_t size, unsigned flags);
__EXPORT int net1_send(int fd, const void* buf, size_t len, unsigned flags);

#endif /* _WASMUX_NET_NET1_H */
