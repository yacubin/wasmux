/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LIBINTL_H
#define _LIBINTL_H

#ifdef __cplusplus
extern "C" {
#endif

char* gettext(const char* msgid);
char* dgettext(const char* domainname, const char* msgid);
char* dngettext(const char* domainname, const char* msgid, const char* msgid_plural, unsigned long n);

char* textdomain (const char* domainname);
char* bindtextdomain (const char* domainname, const char* dirname);

#ifdef __cplusplus
}
#endif

#endif /* _LIBINTL_H */
