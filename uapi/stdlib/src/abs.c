/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <wasmux/math.h>

int abs(int i)
{
  return wasmux_abs(i);
}

long labs(long i)
{
  return wasmux_abs(i);
}

long long llabs(long long i)
{
  return wasmux_abs(i);
}
