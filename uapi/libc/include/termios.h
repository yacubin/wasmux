/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_TERMIOS_H
#define _WA_LIBC_TERMIOS_H

#include <kernel/termios.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IGNBRK 0x001
#define BRKINT 0x002
#define IGNPAR 0x004
#define PARMRK 0x008
#define INPCK  0x010
#define ISTRIP 0x020
#define INLCR  0x040
#define ICRNL  0x100
#define IGNCR  0x080
#define IXANY  0x800

#define OPOST  0x01

#define B0     0x00000000
#define B50    0x00000001
#define B75    0x00000002
#define B110   0x00000003
#define B134   0x00000004
#define B150   0x00000005
#define B200   0x00000006
#define B300   0x00000007
#define B600   0x00000008
#define B1200  0x00000009
#define B1800  0x0000000a
#define B2400  0x0000000b
#define B4800  0x0000000c
#define B9600  0x0000000d
#define B19200 0x0000000e
#define B38400 0x0000000f

#define IUCLC   0x0200
#define IXON    0x0400
#define IXOFF   0x1000
#define IMAXBEL 0x2000

#define CSIZE  0x00000030
#define CS5    0x00000000
#define CS6    0x00000010
#define CS7    0x00000020
#define CS8    0x00000030
#define CSTOPB 0x00000040
#define CREAD  0x00000080
#define PARENB 0x00000100
#define PARODD 0x00000200
#define HUPCL  0x00000400
#define CLOCAL 0x00000800

#define ISIG   0x00001
#define ICANON 0x00002
#define XCASE  0x00004
#define ECHO   0x00008
#define ECHOE  0x00010
#define ECHOK  0x00020
#define ECHONL 0x00040
#define NOFLSH 0x00080
#define IEXTEN 0x08000

typedef unsigned char cc_t;
typedef unsigned int tcflag_t;
typedef unsigned int speed_t;

#define NCCS 19
struct termios {
  tcflag_t c_iflag;
  tcflag_t c_oflag;
  tcflag_t c_cflag;
  tcflag_t c_lflag;
  cc_t c_line;
  cc_t c_cc[NCCS];
};

#define VINTR    0
#define VQUIT    1
#define VERASE   2
#define VKILL    3
#define VEOF     4
#define VTIME    5
#define VMIN     6
#define VSTART   8
#define VSTOP    9
#define VSUSP    10
#define VEOL     11

#define TOSTOP 0x00100

#define TCSANOW   0
#define TCSADRAIN 1
#define TCSAFLUSH 2

/* Constants are used with the tcflow function to manage data flow */
#define TCOOFF 0  /* Pause output */
#define TCOON  1  /* Resume output */
#define TCIOFF 2  /* Pause input */
#define TCION  3  /* Resume input */

#define TCIFLUSH  0
#define TCOFLUSH  1
#define TCIOFLUSH 2

int tcflow(int fd, int action);
int tcgetattr(int fd, struct termios* termios);
int tcsetattr(int fd, int optional_actions, const struct termios* termios);
int tcflush(int fd, int queue_selector);

speed_t cfgetispeed(const struct termios* termios);
speed_t cfgetospeed(const struct termios* termios);
int cfsetispeed(struct termios* termios, speed_t speed);
int cfsetospeed(struct termios* termios, speed_t speed);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_TERMIOS_H */
