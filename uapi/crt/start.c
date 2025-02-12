
/*
 *
 *  Copyright (C) 2024-2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#include <wasmux-config.h>
#include <wasmux/compiler.h>

__ATTR_WEAK
int __main_void(void);

__ATTR_WEAK
int __main_argc_argv(int argc, char** argv)
{
  return __main_void();
}

#if WASMUX_ENABLE_MAIN_ENV_ARG
__ATTR_WEAK
int main(int argc, char** argv, char** env)
{
  return __main_argc_argv(argc, (char**)argv);
}
#endif

__attribute__((export_name("_start")))
void _start(void)
{
  int argc = 0;
  const char* argv[] = { 0 };
#if WASMUX_ENABLE_MAIN_ENV_ARG
  main(argc, (char**)argv, (char**)argv);
#else
  __main_argc_argv(argc, (char**)argv);
#endif
}
