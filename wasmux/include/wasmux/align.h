
/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ALIGN_H
#define _WASMUX_ALIGN_H

#define WA_ALIGN(value, boundary) WA_ALIGN_MASK(value, (__typeof__(value))(boundary) - 1)
#define WA_ALIGN_MASK(value, mask)	(((value) + (mask)) & ~(mask))

#endif /* _WASMUX_ALIGN_H */
