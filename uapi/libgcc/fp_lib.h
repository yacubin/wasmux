/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LIBGCC_FP_LIB_H
#define _LIBGCC_FP_LIB_H

#include <wasmux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int64_t di_int;
typedef uint64_t du_int;

typedef int ti_int __attribute__((mode(TI)));
typedef unsigned tu_int __attribute__((mode(TI)));
typedef __float128 fp_t;

int __letf2(fp_t a, fp_t b);
int __getf2(fp_t a, fp_t b);
void __multi3(ti_int* r, ti_int a, ti_int b);
void __multf3(fp_t* r, fp_t a, fp_t b);
void __addtf3(fp_t* r, fp_t a, fp_t b);
void __subtf3(fp_t* r, fp_t a, fp_t b);
void __divtf3(fp_t* r, fp_t a, fp_t b);
double __trunctfdf2(fp_t a);
float __trunctfsf2(fp_t a);
int __fixtfsi(fp_t a);
di_int __fixtfdi(fp_t a);
void __floatditf(fp_t* r, di_int a);
void __floatunsitf(fp_t* r, unsigned a);
void __extenddftf2(fp_t* r, double a);
void __floatsitf(fp_t* r, int a);
void __floatunditf(fp_t* r, du_int a);
du_int __fixunstfdi(long double input);
int __unordtf2(fp_t a, fp_t b);
void __ashlti3(ti_int* r, ti_int a, int b);
unsigned __fixunstfsi(fp_t a);

#ifdef __cplusplus
}
#endif

#endif /* _LIBGCC_FP_LIB_H */
