/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _FTS_H
#define _FTS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int dummy;
} FTS;

int fts_close(FTS* ftsp);

#ifdef __cplusplus
}
#endif

#endif /* _FTS_H */
