/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include "config.h"

#include <stdio.h>
#include <wasmux/assert.h>
#include <errno.h>

static struct __file_struct s_stream_list[] =
{
  {
    .fd = STDIN_FILENO,
  },
  {
    .fd = STDOUT_FILENO,
  },
  {
    .fd = STDERR_FILENO,
  },
};

struct __file_struct* __get_input_stream()
{
  return &s_stream_list[STDIN_FILENO];
}

struct __file_struct* __get_output_stream()
{
  return &s_stream_list[STDOUT_FILENO];
}

struct __file_struct* __get_error_stream()
{
  return &s_stream_list[STDERR_FILENO];
}

FILE* fdopen(int fd, const char* mode)
{
  WA_UNREACHABLE();
  return nullptr;
}

FILE* fopen(const char* path, const char* mode)
{
  WA_UNREACHABLE();
  return nullptr;
}

FILE* freopen(const char* path, const char* mode, FILE* file)
{
  WA_UNREACHABLE();
  return nullptr;
}

FILE* tmpfile(void)
{
  WA_UNREACHABLE();
  return nullptr;
}

size_t fread(void* ptr, size_t size, size_t n, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return 0;
}

int fgetc(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return EOF;
}

size_t fwrite(const void* ptr, size_t size, size_t n, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return 0;
}

int fputc(int ch, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fputs(const char* str, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fseek(FILE* file, long offset, int whence)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return EOF;
}

int fseeko(FILE* file, off_t offset, int whence)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return EOF;
}

int fclose(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return EOF;
}

off_t ftello(FILE* file)
{
  WA_UNREACHABLE();
  return 1;
}

int feof(FILE* file)
{
  WA_UNREACHABLE();
  return 1;
}

int getc(FILE* file)
{
  WA_UNREACHABLE();
  return EOF;
}

char* fgets(char* str, int n, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int fgetpos(FILE* file, fpos_t* pos)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fsetpos(FILE* file, fpos_t* pos)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int ungetc(int ch, FILE* file)
{
  WA_UNREACHABLE();
  return EOF;
}

long ftell(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void rewind(FILE* file)
{
  WA_UNREACHABLE();
}

int fflush(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}
int ferror(FILE* file)
{
  WA_UNREACHABLE();
  return ENOSYS;
}

void clearerr(FILE* file)
{
  WA_UNREACHABLE();
}

int fileno(FILE* file)
{
  return file->fd;
}

int fscanf(FILE* file, const char* fmt, ...)
{
  WA_UNREACHABLE();
  return -1;
}

void setbuf(FILE* file, char* buf)
{
  WA_UNREACHABLE();
}

int setvbuf(FILE* file, char* buf, int mode, size_t size)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

FILE* popen(const char* command, const char* type)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return nullptr;
}

int pclose(FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

size_t fwrite_unlocked(const void* ptr, size_t size, size_t n, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return 0;
}

int putc_unlocked(int ch, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int fputs_unlocked(const char* str, FILE* file)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int printf(const char* fmt, ...)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int vprintf(const char* fmt, va_list ap)
{
  WA_UNREACHABLE();
  return -1;
}

int sscanf(const char* str, const char* fmt, ...)
{
  WA_UNREACHABLE();
  return -1;
}

int getchar(void)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return EOF;
}

int puts(const char* str)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return EOF;
}

int putchar(int ch)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

void perror(const char* str)
{
  WA_UNREACHABLE();
}

int rename(const char* oldpath, const char* newpath)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

int remove(const char* path)
{
  WA_UNREACHABLE();
  errno = ENOSYS;
  return -1;
}

char* tmpnam(char* str)
{
  WA_UNREACHABLE();
  return nullptr;
}
