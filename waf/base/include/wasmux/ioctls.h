/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_IOCTLS_H
#define _WASMUX_IOCTLS_H

#define TCGETS     0x5401 /* Request code for getting terminal attributes */
#define TIOCSCTTY  0x540E /* Command to set the controlling terminal for the calling process */
#define TIOCGWINSZ 0x5413 /* Request code for getting terminal window size */
#define TIOCSWINSZ 0x5414 /* Command code for setting terminal window size */
#define FIONREAD   0x541B /* Command to get the number of bytes available to read */
#define FIONBIO    0x5421 /* Command to enable or disable non-blocking mode */

#endif /* _WASMUX_IOCTLS_H */
