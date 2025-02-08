/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <semaphore.h>
#include <assert.h>

int sem_init(sem_t* sem, int pshared, unsigned value)
{
  assert(0);
  return -1;
}

int sem_destroy(sem_t* sem)
{
  assert(0);
  return -1;
}

int sem_trywait(sem_t* sem)
{
  assert(0);
  return -1;
}

int sem_wait(sem_t* sem)
{
  assert(0);
  return -1;
}

int sem_getvalue(sem_t* sem, int* val)
{
  assert(0);
  return -1;
}

int sem_post(sem_t* sem)
{
  assert(0);
  return -1;
}
