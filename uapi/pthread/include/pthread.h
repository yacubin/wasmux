/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _PTHREAD_H
#define _PTHREAD_H

#include <wasmux/types.h>
#include <wasmux/time.h>
#include <wasmux/sched.h>
#include <wasmux/cpu_set.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int dummy;
} pthread_mutexattr_t;

typedef struct {
  int dummy;
} pthread_mutex_t;

#define PTHREAD_MUTEX_INITIALIZER (pthread_mutex_t) { 0 }

typedef struct {
  int dummy;
} pthread_once_t;

#define PTHREAD_ONCE_INIT (pthread_once_t) { 0 }

typedef int pthread_key_t;

enum __pthread_mutexattr_type {
  PTHREAD_MUTEX_RECURSIVE,
};

int pthread_mutexattr_init(pthread_mutexattr_t* attr);
int pthread_mutexattr_destroy(pthread_mutexattr_t* attr);
int pthread_mutexattr_gettype(const pthread_mutexattr_t* attr, int* type);
int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type);

int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr);
int pthread_mutex_destroy(pthread_mutex_t* mutex);
int pthread_mutex_trylock(pthread_mutex_t* mutex);
int pthread_mutex_lock(pthread_mutex_t* mutex);
int pthread_mutex_unlock(pthread_mutex_t* mutex);

typedef struct {
  int dummy;
} pthread_condattr_t;

int pthread_condattr_init(pthread_condattr_t* condattr);
int pthread_condattr_destroy(pthread_condattr_t* condattr);
int pthread_condattr_setclock(pthread_condattr_t* condattr, clockid_t clock_id);

typedef struct {
  int dummy;
} pthread_cond_t;

#define PTHREAD_COND_INITIALIZER (pthread_cond_t) { 0 }

int pthread_cond_destroy(pthread_cond_t* cond);
int pthread_cond_init(pthread_cond_t* cond, const pthread_condattr_t* attr);
int pthread_cond_broadcast(pthread_cond_t* cond);
int pthread_cond_signal(pthread_cond_t* cond);
int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex);
int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* abstime);

int pthread_once(pthread_once_t* once, void (*callback)(void));

int pthread_key_create(pthread_key_t* key, void (*destructor)(void*));
int pthread_key_delete(pthread_key_t key);
void* pthread_getspecific(pthread_key_t key);
int pthread_setspecific(pthread_key_t key, const void* val);

typedef struct {
  int dummy;
} pthread_rwlockattr_t;

int pthread_rwlockattr_init(pthread_rwlockattr_t* attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t* attr);
int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t* attr, int kind);
int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t* attr, int* kind);

typedef struct {
  int dummy;
} pthread_rwlock_t;

int pthread_rwlock_init(pthread_rwlock_t* rwlock, const pthread_rwlockattr_t* attr);
int pthread_rwlock_destroy(pthread_rwlock_t* rwlock);
int pthread_rwlock_tryrdlock(pthread_rwlock_t* rwlock);
int pthread_rwlock_rdlock(pthread_rwlock_t* rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t* rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t* rwlock);
int pthread_rwlock_unlock(pthread_rwlock_t* rwlock);

enum __pthread_attr_detachstate {
  PTHREAD_CREATE_JOINABLE = 0,
  PTHREAD_CREATE_DETACHED = 1,
};

typedef struct {
  int dummy;
} pthread_attr_t;

int pthread_attr_init(pthread_attr_t* attr);
int pthread_attr_destroy(pthread_attr_t* attr);
int pthread_attr_setdetachstate(pthread_attr_t* attr, int detachstate);
int pthread_attr_getdetachstate(const pthread_attr_t* attr, int* detachstate);
int pthread_attr_getstacksize(const pthread_attr_t* attr, size_t* stacksize);
int pthread_attr_setstacksize(pthread_attr_t* attr, size_t stacksize);

typedef struct pthread_struct *pthread_t;

int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*callback)(void*), void* arg);
int pthread_detach(pthread_t thread);
int pthread_cancel(pthread_t thread);
int pthread_join(pthread_t thread, void** retval);
int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void));
pthread_t pthread_self(void);
void pthread_exit(void* retval) __attribute__((noreturn));
void pthread_cleanup_push(void (*routine)(void*), void* arg);
void pthread_cleanup_pop(int execute);
int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param* param);
int pthread_getschedparam(pthread_t thread, int* policy, struct sched_param* param);

enum __pthread_cancel_state {
  PTHREAD_CANCEL_ENABLE,
  PTHREAD_CANCEL_DISABLE,
};

int pthread_setcancelstate(int state, int* oldstate);

int pthread_getname_np(pthread_t thread, char* buf, size_t len);
int pthread_setname_np(pthread_t thread, const char* name);

int pthread_getaffinity_np(pthread_t thread, size_t cpuset_size, cpu_set_t* cpuset);
int pthread_setaffinity_np(pthread_t thread, size_t cpuset_size, const cpu_set_t* cpuset);

int pthread_equal(pthread_t a, pthread_t b);

#ifdef __cplusplus
}
#endif

#endif /* _PTHREAD_H */
