/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <grp.h>
#include <assert.h>

struct group* getgrgid(gid_t gid)
{
  assert(0);
  return nullptr;
}

struct group* getgrnam(const char* name)
{
  assert(0);
  return nullptr;
}

int getgrgid_r(gid_t gid, struct group* grp, char* buf, size_t len, struct group** result)
{
  assert(0);
  return -1;
}

int getgrnam_r(const char* name, struct group* grp, char* buf, size_t len, struct group** result)
{
  assert(0);
  return -1;
}

struct group* getgrent(void)
{
  assert(0);
  return nullptr;
}

void setgrent(void)
{
  assert(0);
}

void endgrent(void)
{
  assert(0);
}

int initgroups(const char* user, gid_t group)
{
  assert(0);
  return -1;
}

int setgroups(size_t size, const gid_t* list)
{
  assert(0);
  return -1;
}
