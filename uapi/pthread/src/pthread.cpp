/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"
#include "pthread.h"

#include <kernel/assert.h>

int pthread_mutexattr_init(pthread_mutexattr_t *attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutexattr_destroy(pthread_mutexattr_t *attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutexattr_gettype(const pthread_mutexattr_t* attr, int* type)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutexattr_settype(pthread_mutexattr_t* attr, int type)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutex_destroy(pthread_mutex_t* mutex)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutex_trylock(pthread_mutex_t* mutex)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutex_lock(pthread_mutex_t* mutex)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_mutex_unlock(pthread_mutex_t* mutex)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cond_destroy(pthread_cond_t* cond)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cond_init(pthread_cond_t* cond, const pthread_condattr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cond_broadcast(pthread_cond_t* cond)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cond_signal(pthread_cond_t* cond)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t* mutex, const struct timespec* abstime)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_once(pthread_once_t* once, void (*callback)(void))
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_key_create(pthread_key_t* key, void (*destructor)(void*))
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_key_delete(pthread_key_t key)
{
  WA_UNREACHABLE();
  return -1;
}

void* pthread_getspecific(pthread_key_t key)
{
  WA_UNREACHABLE();
  return nullptr;
}

int pthread_setspecific(pthread_key_t key, const void* val)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlockattr_init(pthread_rwlockattr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlockattr_destroy(pthread_rwlockattr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t* attr, int kind)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t* attr, int* kind)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_init(pthread_rwlock_t* rwlock, const pthread_rwlockattr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_destroy(pthread_rwlock_t* rwlock)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_tryrdlock(pthread_rwlock_t* rwlock)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_rdlock(pthread_rwlock_t* rwlock)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_trywrlock(pthread_rwlock_t* rwlock)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_wrlock(pthread_rwlock_t* rwlock)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_rwlock_unlock(pthread_rwlock_t* rwlock)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_attr_init(pthread_attr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_attr_destroy(pthread_attr_t* attr)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_attr_setdetachstate(pthread_attr_t* attr, int detachstate)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_attr_getdetachstate(const pthread_attr_t* attr, int* detachstate)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_attr_getstacksize(const pthread_attr_t* attr, size_t* stacksize)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_attr_setstacksize(pthread_attr_t* attr, size_t stacksize)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_create(pthread_t* thread, const pthread_attr_t* attr, void* (*callback)(void*), void* arg)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_detach(pthread_t thread)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_cancel(pthread_t thread)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_join(pthread_t thread, void** retval)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void))
{
  WA_UNREACHABLE();
  return -1;
}

pthread_t pthread_self(void)
{
  WA_UNREACHABLE();
  return nullptr;
}

void pthread_exit(void* retval)
{
  WA_UNREACHABLE();
}

void pthread_cleanup_push(void (*routine)(void*), void* arg)
{
  WA_UNREACHABLE();
}

void pthread_cleanup_pop(int execute)
{
  WA_UNREACHABLE();
}

int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param* param)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_getschedparam(pthread_t thread, int* policy, struct sched_param* param)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_setcancelstate(int state, int* oldstate)
{
  WA_UNREACHABLE();
  return -1;
}

int pthread_equal(pthread_t a, pthread_t b)
{
  WA_UNREACHABLE();
  return -1;
}
