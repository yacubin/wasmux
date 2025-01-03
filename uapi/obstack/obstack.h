/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_OBSTACK_OBSTACK_H
#define _WA_OBSTACK_OBSTACK_H

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

#endif /* _WA_OBSTACK_OBSTACK_H */
