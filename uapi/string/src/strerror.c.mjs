import fs from "node:fs";
import path from "node:path";
import url from "node:url";

import { cxx } from "bitmake";

export default async function(mk)
{
  const configUrl = url.pathToFileURL(mk.SCRIPT_INPUT.toString());
  const config = (await import(configUrl)).default;

  const unkErrorStr = "Unknown error";

  const errors = [];
  errors[config.success.code] = config.success.description;
  for (const {code, description} of Object.values(config.errors)) {
    errors[code] = description;
  }

  const lines = [];

  lines.push(cxx.generatedScriptNameComment(import.meta.url));
  lines.push("");
  lines.push("#include <string.h>");
  lines.push("#include <errno.h>");
  lines.push("#include <wasmux/compiler.h>");
  lines.push("");
  lines.push(`static const char* s_errors[${errors.length}] =`);
  lines.push("{");

  for (let code = 0; code < errors.length; ++code) {
    const desc = errors[code] ? `"${errors[code]}"` : "NULL";
    lines.push(`  ${desc},`);
  }

  lines.push("};");
  lines.push("");
  lines.push('char*__ATTR_WEAK strerror(int errnum)');
  lines.push("{");
  lines.push(`  if (errnum < ${errors.length} && s_errors[errnum]) {`);
  lines.push("    return (char*)s_errors[errnum];");
  lines.push("  }");
  lines.push(`  memcpy(__get_local_buffer_data(), "${unkErrorStr}", ${unkErrorStr.length + 1});`);
  /* TODO: Unknown error + atoi(errnum) */
  lines.push("  return __get_local_buffer_data();");
  lines.push("}");
  lines.push("");

  await fs.promises.mkdir(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
