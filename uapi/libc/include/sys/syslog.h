/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_SYSLOG_H
#define _SYS_SYSLOG_H

#include <stdarg.h>
#include <wasmux/compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/* priorities  */
#define LOG_EMERG    0   /* system unusable */
#define LOG_ALERT    1   /* immediate action */
#define LOG_CRIT     2   /* critical condition */
#define LOG_ERR      3   /* error condition */
#define LOG_WARNING  4   /* warning condition */
#define LOG_NOTICE   5   /* normal but significant */
#define LOG_INFO     6   /* informational */
#define LOG_DEBUG    7   /* debug messages */

#define LOG_PRIMASK  7
#define LOG_PRI(priority) ((priority) & LOG_PRIMASK)

#define LOG_UPTO(priority) ((1 << ((priority) + 1)) - 1)

/* facility */
#define LOG_KERN     (0 << 3)
#define LOG_USER     (1 << 3)
#define LOG_MAIL     (2 << 3)
#define LOG_DAEMON   (3 << 3)
#define LOG_AUTH     (4 << 3)
#define LOG_SYSLOG   (5 << 3)
#define LOG_LPR      (6 << 3)
#define LOG_NEWS     (7 << 3)
#define LOG_UUCP     (8 << 3)
#define LOG_CRON     (9 << 3)
#define LOG_AUTHPRIV (10 << 3)
#define LOG_FTP      (11 << 3)
#define LOG_LOCAL0   (16 << 3)
#define LOG_LOCAL1   (17 << 3)
#define LOG_LOCAL2   (18 << 3)
#define LOG_LOCAL3   (19 << 3)
#define LOG_LOCAL4   (20 << 3)
#define LOG_LOCAL5   (21 << 3)
#define LOG_LOCAL6   (22 << 3)
#define LOG_LOCAL7   (23 << 3)

/* options */
#define LOG_PID    0x01
#define LOG_CONS   0x02
#define LOG_ODELAY 0x04
#define LOG_NDELAY 0x08
#define LOG_NOWAIT 0x10
#define LOG_PERROR 0x20

#define INTERNAL_NOPRI 0x10
#define INTERNAL_MARK  0x08

void openlog(const char* ident, int option, int facility);
void closelog(void);
int setlogmask(int mask);
void syslog(int priority, const char* format, ...) __ATTR_PRINTF(2, 3);
void vsyslog(int priority, const char* message, va_list args) __ATTR_PRINTF(2, 0);

typedef struct {
  char* c_name;
  int c_val;
} CODE;

#define prioritynames ((CODE*)(const CODE[]) { \
  { "alert",   LOG_ALERT      }, \
  { "crit",    LOG_CRIT       }, \
  { "debug",   LOG_DEBUG      }, \
  { "emerg",   LOG_EMERG      }, \
  { "err",     LOG_ERR        }, \
  { "error",   LOG_ERR        }, \
	{ "info",    LOG_INFO       }, \
  { "none",    INTERNAL_NOPRI }, \
	{ "notice",  LOG_NOTICE     }, \
  { "panic",   LOG_EMERG      }, \
	{ "warn",    LOG_WARNING    }, \
  { "warning", LOG_WARNING    }, \
  { 0, -1 }})

#define facilitynames ((CODE *)(const CODE []){ \
	{ "auth",     LOG_AUTH      }, \
  { "authpriv", LOG_AUTHPRIV  }, \
	{ "cron",     LOG_CRON      }, \
  { "daemon",   LOG_DAEMON    }, \
  { "ftp",      LOG_FTP       }, \
	{ "kern",     LOG_KERN      }, \
  { "lpr",      LOG_LPR       }, \
  { "mail",     LOG_MAIL      }, \
	{ "mark",     INTERNAL_MARK }, \
  { "news",     LOG_NEWS      }, \
	{ "security", LOG_AUTH      }, \
  { "syslog",   LOG_SYSLOG    }, \
	{ "user",     LOG_USER      }, \
  { "uucp",     LOG_UUCP      }, \
	{ "local0",   LOG_LOCAL0    }, \
  { "local1",   LOG_LOCAL1    }, \
	{ "local2",   LOG_LOCAL2    }, \
  { "local3",   LOG_LOCAL3    }, \
	{ "local4",   LOG_LOCAL4    }, \
  { "local5",   LOG_LOCAL5    }, \
	{ "local6",   LOG_LOCAL6    }, \
  { "local7",   LOG_LOCAL7    }, \
  { 0, -1 } })

#ifdef __cplusplus
}
#endif

#endif /* _SYS_SYSLOG_H */
