/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_LANGINFO_H
#define _WA_LIBC_LANGINFO_H

#include <locale.h>

#define _NL_ITEM(category, index) (((category) << 16) | (index))

#ifdef __cplusplus
extern "C" {
#endif

enum {
  CODESET,
#define CODESET CODESET

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

  D_T_FMT,
#define D_T_FMT D_T_FMT
  D_FMT,
#define D_FMT D_FMT
  T_FMT,
#define T_FMT T_FMT
  T_FMT_AMPM,
#define T_FMT_AMPM T_FMT_AMPM

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
};

typedef int nl_item;

char* nl_langinfo(nl_item item);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_LANGINFO_H */
