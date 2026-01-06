/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <gnu/libc-version.h>

static const char __libc_release[] = "RELEASE";
static const char __libc_version[] = "VERSION";

const char* gnu_get_libc_release(void)
{
  return __libc_release;
}

const char* gnu_get_libc_version(void)
{
  return __libc_version;
}
