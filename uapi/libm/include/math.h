/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _MATH_H
#define _MATH_H

#ifdef __cplusplus
extern "C" {
#endif

#define signbit(x) __builtin_signbit(x)
#define isfinite(x) __builtin_isfinite(x)
#define isnan(x) __builtin_isnan(x)
#define isinf(x) __builtin_isinf(x)

#define NAN      __builtin_nanf("")
#define INFINITY __builtin_inff()
#define HUGE_VAL __builtin_huge_val()

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double acos(double x);
double asin(double x);
double atan(double x);
double tan(double x);

double sinh(double x);
double tanh(double x);
double acosh(double x);
double asinh(double x);
double atanh(double x);
double cosh(double x);
double exp(double x);
double ldexp(double x, int exp);
double frexp(double x, int* exp);

double ceil(double x);
float ceilf(float x);

double floor(double x);
float floorf(float x);

double log(double x);

double sqrt(double x);
float sqrtf(float x);

double cos(double x);
double sin(double x);

double fabs(double x);
float fabsf(float x);
long double fabsl(long double x);

double log2(double x);
double log10(double x);

double trunc(double x);
float truncf(float x);
long double truncl(long double x);

double fmod(double x, double y);
float fmodf(float x, float y);

double copysign(double x, double y);
float copysignf(float x, float y);
long double copysignl(long double x, long double y);

double modf(double x, double* iptr);

double pow(double x, double y);
double atan2(double y, double x);

double rint(double x);
float rintf(float x);

long lrint(double x);

#ifdef __cplusplus
}
#endif

#endif /* _MATH_H */
