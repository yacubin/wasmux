/*
 *
 *  Copyright (C) 2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <fp_lib.h>
#include <wasmux/compiler.h>
#include <wasmux/types.h>

void __multi3(ti_int* r, ti_int a, ti_int b)
{
  uint64_t a_lo = (uint64_t)a;
  uint64_t a_hi = (uint64_t)((tu_int)a >> 64);
  uint64_t b_lo = (uint64_t)b;
  uint64_t b_hi = (uint64_t)((tu_int)b >> 64);

  tu_int lo_lo = (tu_int)a_lo * b_lo;

  uint64_t hi_lo = a_hi * b_lo;
  uint64_t lo_hi = a_lo * b_hi;

  uint64_t mid = (uint64_t)(lo_lo >> 64) + hi_lo + lo_hi;

  *r = ((tu_int)mid << 64) | (uint64_t)lo_lo;
}
