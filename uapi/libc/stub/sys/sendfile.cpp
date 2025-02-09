/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

 #include "config.h"

 #include <sys/signalfd.h>
 #include <assert.h>
 #include <errno.h>
 
ssize_t sendfile(int out_fd, int in_fd, off_t* ofs, size_t count)
 {
   assert(0);
   __set_local_errno(ENOSYS);
   return -1;
 }
 