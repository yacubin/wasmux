/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _KERNEL_NOTIFY_WAITER_H
#define _KERNEL_NOTIFY_WAITER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int flag;
} notify_waiter_t;

#define NOTIFY_WAITER_INFINITE (-1)
#define NOTIFY_WAITER_INIT { .flag = 0 }

void notify_waiter_init(notify_waiter_t*);
int notify_waiter_wait(notify_waiter_t*, int milliseconds);
int notify_waiter_notify(notify_waiter_t*);

#ifdef __cplusplus
}
#endif

#endif /* _KERNEL_NOTIFY_WAITER_H */
