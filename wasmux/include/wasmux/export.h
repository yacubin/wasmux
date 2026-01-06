/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_EXPORT_H
#define _WASMUX_EXPORT_H

#ifdef __cplusplus
# define __EXPORT extern "C"
# define __EXPORT_BEGIN extern "C" {
# define __EXPORT_END }
#else
# define __EXPORT extern
# define __EXPORT_BEGIN
# define __EXPORT_END
#endif

#endif /* _WASMUX_EXPORT_H */
