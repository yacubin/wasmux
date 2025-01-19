module.exports = {
  restart_syscall: { number: 0,   argc: 0 },
  exit:    { number: 1,   argc: 1 },
  fork:    { number: 2,   argc: 0 },
  read:    { number: 3,   argc: 3 },
  write:   { number: 4,   argc: 3 },
  open:    { number: 5,   argc: 3 },
  close:   { number: 6,   argc: 1 },
  waitpid: { number: 7,   argc: 3 },
  creat:   { number: 8,   argc: 2 },
  link:    { number: 9,   argc: 2 },
  unlink:  { number: 10,  argc: 1 },
  execve:  { number: 11,  argc: 3 },
  chdir:   { number: 12,  argc: 1 },
  //time32:  { number: 13,  argc: 1 },
  mknod:   { number: 14,  argc: 3 },
  chmod:   { number: 15,  argc: 2 },
  //lchown16: { number: 16,  argc: 3 },

  lseek:   { number: 19,  argc: 3 },
  getpid:  { number: 20,  argc: 0 },
  mount:   { number: 21,  argc: 5 },

  brk:     { number: 45,  argc: 1 },
  ioctl:   { number: 54,  argc: 3 },
  getcwd:  { number: 183, argc: 2 },

  getuid:  { number: 199, argc: 0 },
  getgid:  { number: 200, argc: 0 },
  geteuid: { number: 201, argc: 0 },

  gettid:  { number: 224, argc: 0 },
}
