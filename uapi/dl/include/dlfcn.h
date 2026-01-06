/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _DLFCN_H
#define _DLFCN_H

#ifdef __cplusplus
extern "C" {
#endif

#define RTLD_LOCAL 0
#define RTLD_LAZY  1
#define RTLD_NOW   2

#define RTLD_GLOBAL 0x00100

void* dlopen(const char* filename, int flag);
char* dlerror(void);
void* dlsym(void* handle, const char* symbol);
int dlclose(void* handle);

typedef struct {
  const char* dli_fname;
  void*       dli_fbase;
  const char* dli_sname;
  void*       dli_saddr;
} Dl_info;

int dladdr(const void* addr, Dl_info* info);

#ifdef __cplusplus
}
#endif

#endif /* _DLFCN_H */
