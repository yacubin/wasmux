/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  long dummy;
} sem_t;

#define SEM_FAILED ((sem_t*)0)

int sem_init(sem_t* sem, int pshared, unsigned value);
int sem_destroy(sem_t* sem);
int sem_trywait(sem_t* sem);
int sem_wait(sem_t* sem);
int sem_getvalue(sem_t* sem, int* val);
int sem_post(sem_t* sem);

#ifdef __cplusplus
}
#endif

#endif /* _SEMAPHORE_H */
