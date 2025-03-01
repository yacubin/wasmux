/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_TTYDEFAULTS_H
#define _SYS_TTYDEFAULTS_H

#define CTRL(x) (x&037)
#define CEOL    '\0'
#define CEOF    CTRL('d')
#define CINTR   CTRL('c')
#define CKILL   CTRL('u')
#define CQUIT   034
#define CERASE  0177

#endif /* _SYS_TTYDEFAULTS_H */
