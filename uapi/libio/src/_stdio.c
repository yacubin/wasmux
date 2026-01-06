/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <stdio.h>
#include <errno.h>
#include <assert.h>

FILE* fdopen(int fd, const char* mode)
{
  assert(0);
  return NULL;
}

FILE* fopen(const char* path, const char* mode)
{
  assert(0);
  return NULL;
}

FILE* freopen(const char* path, const char* mode, FILE* file)
{
  assert(0);
  return NULL;
}

FILE* tmpfile(void)
{
  assert(0);
  return NULL;
}

size_t fread(void* ptr, size_t size, size_t n, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return 0;
}

int fgetc(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return EOF;
}

size_t fwrite(const void* ptr, size_t size, size_t n, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return 0;
}

int fputc(int ch, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fputs(const char* str, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fseek(FILE* file, long offset, int whence)
{
  assert(0);
  errno = ENOSYS;
  return EOF;
}

int fseeko(FILE* file, off_t offset, int whence)
{
  assert(0);
  errno = ENOSYS;
  return EOF;
}

int fclose(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return EOF;
}

off_t ftello(FILE* file)
{
  assert(0);
  return 1;
}

int feof(FILE* file)
{
  assert(0);
  return 1;
}

int getc(FILE* file)
{
  assert(0);
  return EOF;
}

char* fgets(char* str, int n, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return NULL;
}

int fgetpos(FILE* file, fpos_t* pos)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fsetpos(FILE* file, fpos_t* pos)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int ungetc(int ch, FILE* file)
{
  assert(0);
  return EOF;
}

long ftell(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void rewind(FILE* file)
{
  assert(0);
}

int fflush(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}
int ferror(FILE* file)
{
  assert(0);
  return ENOSYS;
}

void clearerr(FILE* file)
{
  assert(0);
}

int fileno(FILE* file)
{
  return file->fd;
}

int fscanf(FILE* file, const char* fmt, ...)
{
  assert(0);
  return -1;
}

void setbuf(FILE* file, char* buf)
{
  assert(0);
}

FILE* popen(const char* command, const char* type)
{
  assert(0);
  errno = ENOSYS;
  return NULL;
}

int pclose(FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

size_t fwrite_unlocked(const void* ptr, size_t size, size_t n, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return 0;
}

int putc_unlocked(int ch, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int fputs_unlocked(const char* str, FILE* file)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int printf(const char* fmt, ...)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int vprintf(const char* fmt, va_list ap)
{
  assert(0);
  return -1;
}

int scanf(const char* fmt, ...)
{
  assert(0);
  return -1;
}

int sscanf(const char* str, const char* fmt, ...)
{
  assert(0);
  return -1;
}

int getchar(void)
{
  assert(0);
  errno = ENOSYS;
  return EOF;
}

int puts(const char* str)
{
  assert(0);
  errno = ENOSYS;
  return EOF;
}

int putchar(int ch)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

void perror(const char* str)
{
  assert(0);
}

int rename(const char* oldpath, const char* newpath)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

int remove(const char* path)
{
  assert(0);
  errno = ENOSYS;
  return -1;
}

char* tmpnam(char* str)
{
  assert(0);
  return NULL;
}
