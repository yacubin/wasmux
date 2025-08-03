/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _GL_INTPROPS_H
#define _GL_INTPROPS_H

#include <stdint.h>

#define TYPE_WIDTH(type) (sizeof(type) * 8)
#define TYPE_SIGNED(type) (((type)0) > ((type)-1))
#define TYPE_MINIMUM(t) (TYPE_SIGNED(type) ? (type)((type)1 << (TYPE_WIDTH(type) - 1)) : (type)0)
#define TYPE_MAXIMUM(type) ((type)(~TYPE_MINIMUM(type)))

#endif /* _GL_INTPROPS_H */
