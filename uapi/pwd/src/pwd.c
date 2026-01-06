/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <pwd.h>
#include <assert.h>

struct passwd* getpwuid(uid_t uid)
{
  assert(0);
  return NULL;
}

struct passwd* getpwnam(const char* name)
{
  assert(0);
  return NULL;
}

int getpwuid_r(uid_t uid, struct passwd* pwd, char* buf, size_t len, struct passwd** result)
{
  assert(0);
  return -1;
}

int getpwnam_r(const char* name, struct passwd* pwd, char* buf, size_t len, struct passwd** result)
{
  assert(0);
  return -1;
}

struct passwd* getpwent(void)
{
  assert(0);
  return NULL;
}

void setpwent(void)
{
  assert(0);
}

void endpwent(void)
{
  assert(0);
}
