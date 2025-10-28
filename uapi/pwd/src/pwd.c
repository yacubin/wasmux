/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <pwd.h>
#include <wasmux/assert.h>

struct passwd* getpwuid(uid_t uid)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct passwd* getpwnam(const char* name)
{
  WA_UNREACHABLE();
  return nullptr;
}

int getpwuid_r(uid_t uid, struct passwd* pwd, char* buf, size_t len, struct passwd** result)
{
  WA_UNREACHABLE();
  return -1;
}

int getpwnam_r(const char* name, struct passwd* pwd, char* buf, size_t len, struct passwd** result)
{
  WA_UNREACHABLE();
  return -1;
}

struct passwd* getpwent(void)
{
  WA_UNREACHABLE();
  return nullptr;
}

void setpwent(void)
{
  WA_UNREACHABLE();
}

void endpwent(void)
{
  WA_UNREACHABLE();
}
