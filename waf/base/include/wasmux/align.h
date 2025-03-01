
/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_ALIGN_H
#define _WA_KERNEL_ALIGN_H

#define WA_ALIGN(value, boundary) WA_ALIGN_MASK(value, (__typeof__(value))(boundary) - 1)
#define WA_ALIGN_MASK(value, mask)	(((value) + (mask)) & ~(mask))

#endif /* _WA_KERNEL_ALIGN_H */
