#include <stdio.h>

#include <libnetq/String.h>
#include <libnetq/Arguments.h>
#include <libnetq/json/JSONWriter.h>

struct ErrnoStruct {
  const char* name;
  const char* message;
  int code;
};

#define NQ_ERRNO_DEF(name, code, message) { #name, message, code },
static const struct ErrnoStruct s_errnos[] = {
# include <libnetq/Errno.def>
};
#undef NQ_ERRNO_DEF

static bool printCallback(void* userdata, const char* characters, size_t size)
{
  printf("%.*s", (int)size, characters);
  return true;
}

void emitErrnoJson()
{
  NQJSONWriter writer;
  NQJSONWriter_init(&writer, printCallback, NULL);
  NQJSONWriter_writeArrayBegin(&writer);
  for (size_t i = 0; i < NQ_ARRAY_LENGTH(s_errnos); i++) {
    const struct ErrnoStruct* iter = &s_errnos[i];
    NQJSONWriter_writeObjectBegin(&writer);
    NQJSONWriter_writeKeyString(&writer, "name", iter->name);
    NQJSONWriter_writeKeyString(&writer, "message", iter->message);
    NQJSONWriter_writeKeyInt32(&writer, "code", iter->code);
    NQJSONWriter_writeObjectEnd(&writer);
  }
  NQJSONWriter_writeArrayEnd(&writer);
  NQJSONWriter_finalize(&writer);
}

static int mainWithArguments(NQArguments* arguments)
{
  size_t i;
  size_t count = NQArguments_count(arguments);
  char buffer[256];

  if (2 <= count) {
    const char* p1 = NQArguments_at(arguments, 1);
    const char* p2 = NQArguments_at(arguments, 2);

    if (!NQStrcmp(p1, "errno-json")) {
      emitErrnoJson();
      return true;
    }
  }

  return false;
}

int main(int argc, const char* argv[])
{
  NQArguments* arguments;
  arguments = NQArguments_create(argc, argv);
  bool success = mainWithArguments(arguments);
  NQArguments_destroy(arguments);
  return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
