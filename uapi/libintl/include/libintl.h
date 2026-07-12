/*
 *
 *  Copyright (C) 2024-2026  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _LIBINTL_H
#define _LIBINTL_H

#ifdef __cplusplus
extern "C" {
#endif

char* gettext(const char* msgid);
char* dgettext(const char* domainname, const char* msgid);
char* ngettext(const char* msgid1, const char* msgid2, unsigned long n);
char* dngettext(const char* domainname, const char* msgid1, const char* msgid2, unsigned long n);

char* textdomain(const char* domainname);
char* bindtextdomain(const char* domainname, const char* dirname);

#ifdef __cplusplus
}
#endif

#endif /* _LIBINTL_H */
