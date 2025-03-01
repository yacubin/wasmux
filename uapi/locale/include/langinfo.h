/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LANGINFO_H
#define _LANGINFO_H

#include <bits/locale_category.h>

#ifdef __cplusplus
extern "C" {
#endif

#define _NL_ITEM(category, index) (((category) << 16) | (index))

enum {
  ABDAY_1 = _NL_ITEM(__LC_TIME, 0),
#define ABDAY_1 ABDAY_1
  ABDAY_2,
#define ABDAY_2 ABDAY_2
  ABDAY_3,
#define ABDAY_3 ABDAY_3
  ABDAY_4,
#define ABDAY_4 ABDAY_4
  ABDAY_5,
#define ABDAY_5 ABDAY_5
  ABDAY_6,
#define ABDAY_6 ABDAY_6
  ABDAY_7,
#define ABDAY_7 ABDAY_7

  DAY_1,
#define DAY_1 DAY_1
  DAY_2,
#define DAY_2 DAY_2
  DAY_3,
#define DAY_3 DAY_3
  DAY_4,
#define DAY_4 DAY_4
  DAY_5,
#define DAY_5 DAY_5
  DAY_6,
#define DAY_6 DAY_6
  DAY_7,
#define DAY_7 DAY_7

  ABMON_1,
#define ABMON_1 ABMON_1
  ABMON_2,
#define ABMON_2 ABMON_2
  ABMON_3,
#define ABMON_3 ABMON_3
  ABMON_4,
#define ABMON_4 ABMON_4
  ABMON_5,
#define ABMON_5 ABMON_5
  ABMON_6,
#define ABMON_6 ABMON_6
  ABMON_7,
#define ABMON_7 ABMON_7
  ABMON_8,
#define ABMON_8 ABMON_8
  ABMON_9,
#define ABMON_9 ABMON_9
  ABMON_10,
#define ABMON_10 ABMON_10
  ABMON_11,
#define ABMON_11 ABMON_11
  ABMON_12,
#define ABMON_12 ABMON_12

  MON_1,
#define MON_1 MON_1
  MON_2,
#define MON_2 MON_2
  MON_3,
#define MON_3 MON_3
  MON_4,
#define MON_4 MON_4
  MON_5,
#define MON_5 MON_5
  MON_6,
#define MON_6 MON_6
  MON_7,
#define MON_7 MON_7
  MON_8,
#define MON_8 MON_8
  MON_9,
#define MON_9 MON_9
  MON_10,
#define MON_10 MON_10
  MON_11,
#define MON_11 MON_11
  MON_12,
#define MON_12 MON_12

  AM_STR,
#define AM_STR AM_STR

  PM_STR,
#define PM_STR PM_STR

  D_T_FMT,
#define D_T_FMT D_T_FMT
  D_FMT,
#define D_FMT D_FMT
  T_FMT,
#define T_FMT T_FMT
  T_FMT_AMPM,
#define T_FMT_AMPM T_FMT_AMPM

  ERA,
#define ERA ERA
  ERA_D_FMT,
#define ERA_D_FMT ERA_D_FMT
  ALT_DIGITS,
#define ALT_DIGITS ALT_DIGITS
  ERA_D_T_FMT,
#define ERA_D_T_FMT ERA_D_T_FMT
  ERA_T_FMT,
#define ERA_T_FMT ERA_T_FMT

  _NL_TIME_ERA_NUM_ENTRIES,

  ALTMON_1,
#define ALTMON_1 ALTMON_1
  ALTMON_2,
#define ALTMON_2 ALTMON_2
  ALTMON_3,
#define ALTMON_3 ALTMON_3
  ALTMON_4,
#define ALTMON_4 ALTMON_4
  ALTMON_5,
#define ALTMON_5 ALTMON_5
  ALTMON_6,
#define ALTMON_6 ALTMON_6
  ALTMON_7,
#define ALTMON_7 ALTMON_7
  ALTMON_8,
#define ALTMON_8 ALTMON_8
  ALTMON_9,
#define ALTMON_9 ALTMON_9
  ALTMON_10,
#define ALTMON_10 ALTMON_10
  ALTMON_11,
#define ALTMON_11 ALTMON_11
  ALTMON_12,
#define ALTMON_12 ALTMON_12

  RADIXCHAR,
#define RADIXCHAR RADIXCHAR
  THOUSEP,
#define THOUSEP THOUSEP

  CODESET,
#define CODESET CODESET

  _NL_CTYPE_OUTDIGIT0_MB,
  _NL_CTYPE_OUTDIGIT1_MB,
  _NL_CTYPE_OUTDIGIT2_MB,
  _NL_CTYPE_OUTDIGIT3_MB,
  _NL_CTYPE_OUTDIGIT4_MB,
  _NL_CTYPE_OUTDIGIT5_MB,
  _NL_CTYPE_OUTDIGIT6_MB,
  _NL_CTYPE_OUTDIGIT7_MB,
  _NL_CTYPE_OUTDIGIT8_MB,
  _NL_CTYPE_OUTDIGIT9_MB,
};

typedef int nl_item;

char* nl_langinfo(nl_item item);

#ifdef __cplusplus
}
#endif

#endif /* _LANGINFO_H */
