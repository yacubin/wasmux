/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SEARCH_H
#define _SEARCH_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  preorder,
  postorder,
  endorder,
  leaf,
} VISIT;

void* tsearch(const void* key, void** root, int (*compare)(const void*, const void*));
void* tfind(const void* key, void* const* root, int (*compare)(const void*, const void*));
void* tdelete(const void* key, void ** root, int (*compare)(const void*, const void*));
void twalk(const void* root, void (*action)(const void* node, VISIT which, int depth));

#ifdef __cplusplus
}
#endif

#endif /* _SEARCH_H */
