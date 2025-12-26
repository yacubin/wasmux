/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdlib.h>
#include <assert.h>
#include <errno.h>

int system(const char* command)
{
  assert(0);
  return -1;
}

void srand(unsigned seed)
{
  assert(0);
}

int rand(void)
{
  assert(0);
  return -1;
}

void srandom(unsigned seed)
{
  assert(0);
}

long random(void)
{
  assert(0);
  return -1;
}

char* initstate(unsigned seed, char* state, size_t n)
{
  assert(0);
  errno = ENOSYS;
  return NULL;
}

char* setstate(char* state)
{
  assert(0);
  errno = ENOSYS;
  return NULL;
}

double drand48(void)
{
  assert(0);
  return 0.0;
}

int mkstemp(char* temp)
{
  assert(0);
  return -1;
}

char* mktemp(char* pattern)
{
  assert(0);
  errno = ENOSYS;
  return NULL;
}

char* mkdtemp(char* pattern)
{
  assert(0);
  errno = ENOSYS;
  return NULL;
}

int grantpt(int fd)
{
  assert(0);
  return -1;
}

char* ptsname(int fd)
{
  assert(0);
  return NULL;
}

int unlockpt(int fd)
{
  assert(0);
  return -1;
}
