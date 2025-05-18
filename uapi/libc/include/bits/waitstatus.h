/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef WEXITSTATUS
# define WEXITSTATUS(status) (((status) & 0xff00) >> 8)
#endif

#ifndef WIFEXITED
#define WIFEXITED(status) (((status) & 0x7f) == 0)
#endif

#ifndef WTERMSIG
#define WTERMSIG(status)    ((status) & 0x7f)
#endif

#ifndef WIFSIGNALED
#define WIFSIGNALED(status) ((status) - 1 < 0xff)
#endif

#ifndef WIFSTOPPED
#define WIFSTOPPED(status)  (((status) & 0xff) == 0x7f)
#endif
