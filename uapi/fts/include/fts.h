/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_FTS_FTS_H
#define _WA_FTS_FTS_H

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

#endif /* _WA_FTS_FTS_H */
