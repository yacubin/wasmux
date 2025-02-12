/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <errno.h>
#include <string.h>
#include <wasmux/compiler.h>

__ATTR_HIDDEN
extern "C" int __gethostname(char* name, size_t len)
{
  struct utsname buf;
  if (uname(&buf) == 0)
    return -1;

  size_t lenz = strnlen(buf.nodename, sizeof(buf.nodename)) + 1;
  if (len < lenz) {
    __set_local_errno(ENAMETOOLONG);
    return -1;
  }

  memcpy(name, buf.nodename, lenz);
  return 0;
}

extern "C" __ATTR_ALIAS(__gethostname, gethostname) __ATTR_WEAK;
