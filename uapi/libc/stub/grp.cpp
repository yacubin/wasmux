/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "grp.h"

#include <kernel/assert.h>

struct group* getgrgid(gid_t gid)
{
  WA_UNREACHABLE();
  return nullptr;
}

struct group* getgrnam(const char* name)
{
  WA_UNREACHABLE();
  return nullptr;
}

int getgrnam_r(const char* name, struct group* grp, char* buf, size_t len, struct group** result)
{
  WA_UNREACHABLE();
  return -1;
}

struct group* getgrent(void)
{
  WA_UNREACHABLE();
  return nullptr;
}

void setgrent(void)
{
  WA_UNREACHABLE();
}

void endgrent(void)
{
  WA_UNREACHABLE();
}

int initgroups(const char* user, gid_t group)
{
  WA_UNREACHABLE();
  return -1;
}

int setgroups(size_t size, const gid_t* list)
{
  WA_UNREACHABLE();
  return -1;
}
