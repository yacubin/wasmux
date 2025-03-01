#ifdef __MINGW32__
extern "C" int atexit(void (*__func) (void))
{
  return 0;
}
#else
__attribute__ ((visibility ("hidden")))
extern "C" int __cxa_atexit(void (*destructor) (void* ptr), void* ptr, void* dso_handle)
{
  // TODO: Add distructor to array
  //       (-1) if could not add function
  //       lock/unlock

  return 0;
}
#endif
