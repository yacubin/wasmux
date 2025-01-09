/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_ERRNO_H
#define _WASMUX_ERRNO_H

#define EPERM          1    /* Operation not permitted */
#define ENOENT         2    /* No such file or directory */
#define ESRCH          3    /* No such process */
#define EINTR          4    /* Interrupted function call */
#define EIO            5    /* Input/output error */
#define ENXIO          6    /* No such device or address */
#define E2BIG          7    /* Argument list too long */
#define ENOEXEC        8    /* Exec format error */
#define EBADF          9    /* Bad file descriptor */
#define ECHILD         10   /* No child processes */
#define EAGAIN         11   /* Resource temporarily unavailable */
#define ENOMEM         12   /* Out of memory */
#define EACCES         13   /* Permission denied */
#define EFAULT         14   /* Bad address error */
#define EBUSY          16   /* Device or resource busy */
#define EEXIST         17   /* File exists */
#define EXDEV          18   /* Invalid cross-device link */
#define ENODEV         19   /* No such device */
#define ENOTDIR        20   /* Not a directory */
#define EISDIR         21   /* Is a directory */
#define EINVAL         22   /* Invalid argument */
#define ENFILE         23   /* File table overflow */
#define EMFILE         24   /* Too many open files */
#define ENOTTY         25   /* Inappropriate I/O control operation */
#define ETXTBSY        26   /* Text file busy */
#define EFBIG          27   /* File too large */
#define ENOSPC         28   /* No space left on device */
#define ESPIPE         29   /* Invalid seek */
#define EROFS          30   /* Read-only filesystem */
#define EMLINK         31   /* Too many links */
#define EPIPE          32   /* Broken pipe */
#define ERANGE         34   /* Math result not representable */
#define ENAMETOOLONG   36   /* Filename too long */
#define ENOLCK         37   /* No locks available */
#define ENOSYS         38   /* Function not implemented */
#define ENOTEMPTY      39   /* Directory not empty */
#define ELOOP          40   /* Too many levels of symbolic links */
#define ENOMSG         42   /* No message of the desired type */
#define EOVERFLOW      75   /* Value too large to be stored in data type */
#define EILSEQ         84   /* Invalid or incomplete multibyte or wide character */
#define ENODATA        86   /* The named attribute does not exist */
#define ENOTSOCK       88   /* Not a socket */
#define ENOTSUP        95   /* Operation not supported */
#define	EOPNOTSUPP     95   /* Operation not supported on socket */
#define EAFNOSUPPORT   97   /* Address family not supported */
#define EADDRNOTAVAIL  99   /* Address not available */
#define ECONNABORTED   103  /* Connection aborted */
#define EISCONN        106  /* Socket is connected */
#define ENOTCONN       107  /* The socket is not connected */
#define ETIMEDOUT      110  /* Connection timed out */
#define EINPROGRESS    115  /* Operation in progress */
#define ESTALE         116  /* Stale file handle */
#define EDQUOT         122  /* Disk quota exceeded */
#define ECANCELED      125  /* Operation canceled */

#define ENOATTR     ENODATA
#define EWOULDBLOCK EAGAIN

#endif /* _WASMUX_ERRNO_H */
