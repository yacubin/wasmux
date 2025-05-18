/*
 *
 *  Copyright (C) 2024  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WA_KERNEL_MUTEX_H
#define _WA_KERNEL_MUTEX_H

#ifdef __cplusplus
extern "C" {
#endif

#define WA_MUTEX_INITIALIZER { 0 }
#define WA_DEFINE_MUTEX(mutexname) \
	wa_mutex_t mutexname = WA_MUTEX_INITIALIZER

typedef struct {
  int value;
} wa_mutex_t;

#define wa_mutex_init(lock) \
  do { (lock)->value = 0; } while(0)

#ifdef __wasm__
void __mutex_lock(int* mutex_value);
int __mutex_trylock(int* mutex_value);
void __mutex_unlock(int* mutex_value);

#define wa_mutex_lock(lock) \
  __mutex_lock(&(lock)->value)

#define  wa_mutex_trylock(lock) \
  __mutex_trylock(&(lock)->value)

#define wa_mutex_unlock(lock) \
  __mutex_unlock(&(lock)->value)

#else

static inline void wa_mutex_lock(wa_mutex_t* mutex)
{
  int expected;
  do {
    expected = 0;
    __atomic_compare_exchange_n(&mutex->value, &expected, 1, 0, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
  } while (expected != 0);
}

static inline int wa_mutex_trylock(wa_mutex_t* mutex)
{
  int expected = 0;
  return __atomic_compare_exchange_n(&mutex->value, &expected, 1, 0, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
}

static inline void wa_mutex_unlock(wa_mutex_t* mutex)
{
  __atomic_store_n(&mutex->value, 0, __ATOMIC_RELEASE);
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* _WA_KERNEL_MUTEX_H */
