/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <fp_lib.h>
#include <wasmux/compiler.h>
#include <wasmux/assert.h>

int __letf2(fp_t a, fp_t b)
{
  WA_UNREACHABLE();
  return 0;
}

extern "C" __ATTR_ALIAS(__letf2, __eqtf2);
extern "C" __ATTR_ALIAS(__letf2, __lttf2);
extern "C" __ATTR_ALIAS(__letf2, __netf2);

int __getf2(fp_t a, fp_t b)
{
  WA_UNREACHABLE();
  return 0;
}

extern "C" __ATTR_ALIAS(__getf2, __gttf2);

void __multi3(ti_int* r, ti_int a, ti_int b)
{
  WA_UNREACHABLE();
}

void __multf3(fp_t* r, fp_t a, fp_t b)
{
  WA_UNREACHABLE();
}

void __addtf3(fp_t* r, fp_t a, fp_t b)
{
  WA_UNREACHABLE();
}

void __subtf3(fp_t* r, fp_t a, fp_t b)
{
  WA_UNREACHABLE();
}

void __divtf3(fp_t* r, fp_t a, fp_t b)
{
  WA_UNREACHABLE();
}

double __trunctfdf2(fp_t a)
{
  WA_UNREACHABLE();
  return 0.0;
}

float __trunctfsf2(fp_t a)
{
  WA_UNREACHABLE();
  return 0.0;
}

int __fixtfsi(fp_t a)
{
  WA_UNREACHABLE();
  return 0;
}

di_int __fixtfdi(fp_t a)
{
  WA_UNREACHABLE();
}

void __floatunsitf(fp_t* r, unsigned a)
{
  WA_UNREACHABLE();
}

void __floatditf(fp_t* r, di_int a)
{
  WA_UNREACHABLE();
}

void __extenddftf2(fp_t* r, double a)
{
  WA_UNREACHABLE();
}

void __floatsitf(fp_t* r, int a)
{
  WA_UNREACHABLE();
}

void __floatunditf(fp_t* r, du_int a)
{
  WA_UNREACHABLE();
}

du_int __fixunstfdi(long double input)
{
  WA_UNREACHABLE();
  return 0;
}

int __unordtf2(fp_t a, fp_t b)
{
  WA_UNREACHABLE();
  return 0;
}

void __ashlti3(ti_int* r, ti_int a, int b)
{
  WA_UNREACHABLE();
}

unsigned __fixunstfsi(fp_t a)
{
  WA_UNREACHABLE();
  return 0;
}
