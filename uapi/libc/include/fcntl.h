/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_FCNTL_H
#define _WA_LIBC_FCNTL_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Command values for fcntl */
#define F_DUPFD          0    /* Duplicate file descriptor */
#define F_GETFD          1    /* Get file descriptor flags */
#define F_SETFD          2    /* Set file descriptor flags */
#define F_GETFL          3    /* Get file status flags */
#define F_SETFL          4    /* Set file status flags */
#define F_GETLK          5    /* Check for existing conflicting locks */
#define F_SETLK          6    /* Set a lock (non-blocking) */
#define F_SETLKW         7    /* Set a lock, waiting if necessary */
#define F_SETOWN         8	  /* Set process to receive SIGIO signals */
#define F_DUPFD_CLOEXEC  103  /* Duplicate file descriptor with FD_CLOEXEC */

/* File access mode masks (for F_GETFL/F_SETFL) */
#define O_RDONLY   0  /* Open for reading only */
#define O_WRONLY   1  /* Open for writing only */
#define O_RDWR     2  /* Open for reading and writing */
#define O_ACCMODE  3  /* Mask for access modes */

/* Open flags */
#define O_CREAT      0x00000040  /* Create file if it does not exist */
#define O_EXCL       0x00000080  /* Exclusive use flag */
#define O_NOCTTY     0x00000100  /* Do not assign controlling terminal */
#define O_TRUNC      0x00000200  /* Truncate flag */
#define O_ASYNC      0x00002000  /* Enables async I/O signals */

#define O_SEARCH     0x00001000
#define O_NONBLOCK   0x00004000
#define O_DIRECTORY  0x00010000
#define O_CLOEXEC    0x00080000

#define O_APPEND     0x00000008

#define F_RDLCK   0
#define F_WRLCK   1
#define F_UNLCK   2

struct flock {
  short l_type;
  short l_whence;
  off_t l_start;
  off_t l_len;
  pid_t l_pid;
};

int fcntl(int fd, int cmd, ...);
int open(const char* path, int flags, ...);
int creat(const char* path, mode_t mode);

#ifdef __cplusplus
}
#endif

#endif /* _WA_LIBC_FCNTL_H */
