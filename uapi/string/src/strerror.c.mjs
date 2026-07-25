import path from "node:path";
import fs from "node:fs";

const [ ,, input, output ] = process.argv;

const content = await fs.promises.readFile(input, "utf8");
const errors = JSON.parse(content).sort((a, b) => a.code - b.code);

let maxCode = Math.max(...errors.map(i => i.code));
const errorsLength = maxCode + 1;

const lines = [];

const unkErrorStr = "Unknown error";

lines.push("");
lines.push("#include <string.h>");
lines.push("#include <errno.h>");
lines.push("#include <wasmux/compiler.h>");
lines.push("");
lines.push(`static const char* s_errors[${errorsLength}] =`);
lines.push("{");

for (let code = 0; code < errorsLength; code++) {
  const item = errors.find(i => i.code === code);
  let message;
  if (code === 0)
    message = "No error information";
  else if (item)
    message = item.message;
  lines.push(`  ${message ? '"' + message + '"' : "NULL"},`);
}

lines.push("};");
lines.push("");
lines.push('char*__ATTR_WEAK strerror(int errnum)');
lines.push("{");
lines.push(`  if (errnum < ${errorsLength} && s_errors[errnum]) {`);
lines.push("    return (char*)s_errors[errnum];");
lines.push("  }");
lines.push(`  memcpy(__get_local_buffer_data(), "${unkErrorStr}", ${unkErrorStr.length + 1});`);
/* TODO: Unknown error + atoi(errnum) */
lines.push("  return __get_local_buffer_data();");
lines.push("}");
lines.push("");

await fs.promises.mkdir(path.dirname(output), { recursive: true });
await fs.promises.writeFile(output, lines.join('\n'), "utf8");
