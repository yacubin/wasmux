/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _STDIO_H
#define _STDIO_H

#include <wasmux/compiler.h>
#include <wasmux/stdarg.h>
#include <wasmux/fs.h>

#include <features.h>
#include <stddef.h>
#include <bits/file_struct.h>
#include <sys/stat.h>

#ifdef __cplusplus
extern "C" {
#endif

extern FILE* const stdin;
extern FILE* const stdout;
extern FILE* const stderr;

#define stdin  stdin
#define stdout stdout
#define stderr stderr

#define SEEK_SET 0  // Beginning of the file
#define SEEK_CUR 1  // Current position in the file
#define SEEK_END 2  // End of the file

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define FILENAME_MAX 1024
#define BUFSIZ 8192

#define EOF (-1)

#define P_tmpdir "/tmp"

typedef off_t fpos_t;

FILE* fdopen(int fd, const char* mode);
FILE* fopen(const char* path, const char* mode);
FILE* freopen(const char* path, const char* mode, FILE* file);
FILE* tmpfile(void);
size_t fread(void* ptr, size_t size, size_t n, FILE* file);
size_t fwrite(const void* ptr, size_t size, size_t n, FILE* file);
int fprintf(FILE* file, const char* fmt, ...);
int vfprintf(FILE* file, const char* fmt, va_list ap);
int fgetc(FILE* file);
int fputc(int ch, FILE* file);
int fputs(const char* str, FILE* file);
int fseek(FILE* file, long offset, int whence);
int fseeko(FILE* file, off_t offset, int whence);
int fclose(FILE* file);
off_t ftello(FILE* file);
int putc(int ch, FILE* file);
int feof(FILE* file);
int getc(FILE* file);
char* fgets(char* str, int n, FILE* file);
int fgetpos(FILE* file, fpos_t* pos);
int fsetpos(FILE* file, fpos_t* pos);
int ungetc(int ch, FILE* file);
long ftell(FILE* file);
void rewind(FILE* file);
int fflush(FILE* file);
int ferror(FILE* file);
void clearerr(FILE* file);
int fileno(FILE* file);
int fscanf(FILE* file, const char* fmt, ...);
int getc_unlocked(FILE* file);

void flockfile(FILE* file);
int ftrylockfile(FILE* file);
void funlockfile(FILE* file);

ssize_t getline(char** line, size_t* n, FILE* file);
ssize_t getdelim(char** line, size_t* n, int delim, FILE* file);

void setbuf(FILE* file, char* buf);
int setvbuf(FILE* file, char* buf, int mode, size_t size);

FILE* popen(const char* command, const char* type);
int pclose(FILE* file);

size_t fwrite_unlocked(const void* ptr, size_t size, size_t n, FILE* file);
int putc_unlocked(int ch, FILE* file);
int fputs_unlocked(const char* str, FILE* file);

int sprintf(char* str, const char* fmt, ...) __ATTR_PRINTF(2, 3);
int vsprintf(char* str, const char* fmt, va_list ap) __ATTR_PRINTF(2, 0);
int snprintf(char* str, size_t len, const char* fmt, ...) __ATTR_PRINTF(3, 4);
int vsnprintf(char* str, size_t len, const char* fmt, va_list ap) __ATTR_PRINTF(3, 0);
int asprintf(char** str, const char* fmt, ...) __ATTR_PRINTF(2, 3);
int vasprintf(char** str, const char* fmt, va_list ap) __ATTR_PRINTF(2, 0);
int printf(const char* fmt, ...);
int vprintf(const char* fmt, va_list ap);
int scanf(const char* fmt, ...);
int sscanf(const char* str, const char* fmt, ...);
int getchar(void);
int putc(int ch, FILE* file);
int puts(const char* str);
int putchar(int ch);
void perror(const char* str);

int rename(const char* oldpath, const char* newpath);
int remove(const char* path);

char* tmpnam(char* str);

#ifdef __cplusplus
}
#endif

#endif /* _STDIO_H */
