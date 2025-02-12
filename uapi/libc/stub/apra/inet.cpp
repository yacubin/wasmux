/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <arpa/inet.h>
#include <wasmux/assert.h>

char* inet_ntoa(struct in_addr in)
{
  WA_UNREACHABLE();
  return nullptr;
}

int inet_pton(int af, const char* src, void* dst)
{
  WA_UNREACHABLE();
  return -1;
}
