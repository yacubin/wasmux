/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_FILE_SYSTEM_H
#define _WASMUX_FILE_SYSTEM_H

#include <wasmux/types.h>
#include <wasmux/wei.h>
#include <wasmux/web/string.h>
#include <wasmux/web/arraybuffer.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WebMainFileSystem WebMainFileSystem;
struct WebMainFileSystem {
  WEI_Object rootObj;
};

typedef struct WebMainFileStat {
  unsigned size;
} WebMainFileStat;

typedef enum WebMainFileAccess {
  kWebFileExistsAccess = 0,
  kWebFileExecuteAccess = 1,
  kWebFileWriteAccess = 2,
  kWebFileReadAccess = 4,
} WebMainFileAccess;

void WebMainFileSystem_init(WebMainFileSystem*);
void WebMainFileSystem_finalize(WebMainFileSystem*);

int WebMainFileSystem_statSync(WebMainFileSystem*, const WebString* path, WebMainFileStat* stat);
int WebMainFileSystem_openSync(WebMainFileSystem*, const WebString* path);
int WebMainFileSystem_readSync(WebMainFileSystem*, int fd, unsigned offset, void* buf, unsigned size);
int WebMainFileSystem_accessSync(WebMainFileSystem*, const WebString* path, int mode);

#ifdef __cplusplus
}
#endif

#endif /* _WASMUX_FILE_SYSTEM_H */
