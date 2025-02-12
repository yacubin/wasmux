/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <sys/stat.h>
#include <paths.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

char* ttyname(int fd)
{
  char* buf = __get_local_buffer_data();
  int ret = ttyname_r(fd, buf, __get_local_buffer_size());
  if (ret != 0) {
    __set_local_errno(ret);
    return nullptr;
  }

  return buf;
}

int ttyname_r(int fd, char* buf, size_t len)
{
  struct termios termios;
  if (tcgetattr(fd, &termios) < 0) {
    __set_local_errno(EBADF);
    return -1;
  }

  struct stat fd_stat;
  if (fstat(fd, &fd_stat) || !S_ISCHR(fd_stat.st_mode)) {
    __set_local_errno(EBADF);
    return -1;
  }

  DIR* dir = opendir(_PATH_DEV);
  if (dir == nullptr) {
    __set_local_errno(EBADF);
    return -1;
  }

  strncpy(buf, _PATH_DEV, len);

  do {
    struct dirent* iter = readdir(dir);
    if (iter->d_ino != fd_stat.st_ino)
      continue;
    strcpy(buf + sizeof(_PATH_DEV) - 1, iter->d_name);
    struct stat iter_stat;
    if (stat(buf, &iter_stat) != 0 || fd_stat.st_dev != iter_stat.st_dev || fd_stat.st_ino != iter_stat.st_ino)
      continue;
  } while(0);
  
  closedir(dir);
  return 0;
}
