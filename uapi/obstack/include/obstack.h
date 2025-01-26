/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _OBSTACK_H
#define _OBSTACK_H

#ifdef __cplusplus
extern "C" {
#endif

struct obstack {
  int dummy;
};

void _obstack_free(struct obstack* obstack, void* obj);

#ifdef __cplusplus
}
#endif

#endif /* _OBSTACK_H */
