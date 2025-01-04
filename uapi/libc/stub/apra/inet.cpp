/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "arpa/inet.h"

#include <kernel/assert.h>

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
