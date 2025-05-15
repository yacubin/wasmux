/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_SYSINFO_H
#define _WASMUX_SYSINFO_H

struct sysinfo {
  unsigned long uptime;
  unsigned long loads[3];
  unsigned long totalram;
  unsigned long freeram;
  unsigned long sharedram;
  unsigned long bufferram;
  unsigned long totalswap;
  unsigned long freeswap;
  unsigned short procs;
  unsigned short pad;
  unsigned long totalhigh;
  unsigned long freehigh;
  unsigned mem_unit;
  char _f[20 - 2 * sizeof(long) - sizeof(unsigned)];
};

#endif /* _WASMUX_SYSINFO_H */
