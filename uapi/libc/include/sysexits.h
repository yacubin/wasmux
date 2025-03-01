/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_LIBC_SYSEXITS_H
#define _WA_LIBC_SYSEXITS_H

#define EX_OK          0   /* Successful termination */

#define EX_USAGE       64  /* Command-line usage error */
#define EX_DATAERR     65  /* Input data is invalid or corrupted */
#define EX_NOINPUT     66  /* Cannot open input */
#define EX_NOUSER      67  /* Addressee unknown (e.g., user does not exist) */
#define EX_NOHOST      68  /* Hostname unknown */
#define EX_UNAVAILABLE 69  /* Required service or resource unavailable */
#define EX_SOFTWARE    70  /* Internal software error */
#define EX_OSERR       71  /* System error (e.g., fork or pipe issue) */
#define EX_OSFILE      72  /* System file missing */
#define EX_CANTCREAT   73  /* Cannot create output file */
#define EX_IOERR       74  /* Input/output error during operation */
#define EX_TEMPFAIL    75  /* Temporary failure (e.g., try again later) */
#define EX_PROTOCOL    76  /* Protocol error */
#define EX_NOPERM      77  /* Permission denied */
#define EX_CONFIG      78  /* Configuration error */

#endif /* _WA_LIBC_SYSEXITS_H */
