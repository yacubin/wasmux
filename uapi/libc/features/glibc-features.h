/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _FEATURES_H
#define _FEATURES_H

#ifdef	__cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#define __GNU_LIBRARY__ 6
#define __GLIBC__ 2
#define __GLIBC_MINOR__ 40

#endif /* _FEATURES_H */
