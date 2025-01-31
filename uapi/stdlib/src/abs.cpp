/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <stdlib.h>
#include <wasmux/cxx/Math.h>

int abs(int i)
{
  return WAF::abs(i);
}

long labs(long i)
{
  return WAF::abs(i);
}

long long llabs(long long i)
{
  return WAF::abs(i);
}
