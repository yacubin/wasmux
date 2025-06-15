/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_IOCTLS_H
#define _WASMUX_IOCTLS_H

#define TCGETS     0x5401     /* Request code for getting terminal attributes */
#define TCSETS     0x5402     /* Request code for setting terminal attributes */
#define TCSBRK     0x5409     /* Command to send a break on the terminal line */
#define TCXONC     0x540A     /* Command to control XON/XOFF flow control */
#define TCFLSH     0x540B     /* Command to flush terminal input/output queues */
#define TIOCSCTTY  0x540E     /* Command to set the controlling terminal for the calling process */
#define TIOCGPGRP  0x540F     /* Command to get the process group ID of the terminal */
#define TIOCGWINSZ 0x5413     /* Request code for getting terminal window size */
#define TIOCSWINSZ 0x5414     /* Command code for setting terminal window size */
#define FIONREAD   0x541B     /* Command to get the number of bytes available to read */
#define FIONBIO    0x5421     /* Command to enable or disable non-blocking mode */
#define TIOCGSID   0x5429     /* Command to get the session ID of the terminal */
#define TIOCGPTN   0x80045430 /* Command to get the PTY number of a pseudoterminal */

#endif /* _WASMUX_IOCTLS_H */
