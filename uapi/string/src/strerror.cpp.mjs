import url from 'node:url';
import * as CXX from "###/utils/CXX.js";

export const ARGS = {
  INPUT:  { type: "string", name: "input"  },
  OUTPUT: { type: "string", name: "output" },
};

export default async function(ctx, {input, output})
{
  if (!input) {
    throw "Not pass the binary dir";
  }

  if (!output) {
    throw "Not pass the output";
  }

  const inputUrl = url.pathToFileURL(input);
  const module = await import(inputUrl);

  const config = {
    success: module.success || {},
    errors: module.errors || {},
    aliases: module.aliases || {},
  };

  ctx.hooks.emit("strerror.cpp", config);

  const unkErrorStr = "Unknown error";

  const errors = [];
  errors[config.success.code] = config.success.description;
  for (const {code, description} of Object.values(config.errors)) {
    errors[code] = description;
  }

  const lines = [];

  lines.push(CXX.generatedScriptNameComment(ctx.entryScript));
  lines.push("");
  lines.push("#include <wasmux-config.h>");
  lines.push("#include <string.h>");
  lines.push("#include <errno.h>");
  lines.push("#include <wasmux/compiler.h>");
  lines.push("#include <wasmux/thread_data.h>");
  lines.push("");
  lines.push(`static const char* s_errors[${errors.length}] =`);
  lines.push("{");
  for (let code = 0; code < errors.length; ++code) {
    const desc = errors[code] ? `"${errors[code]}"` : "nullptr";
    lines.push(`  ${desc},`);
  }
  lines.push("};");
  lines.push("");
  lines.push('extern "C" char* __strerror(int errnum)');
  lines.push("{");
  lines.push(`  if (errnum < ${errors.length} && s_errors[errnum]) {`);
  lines.push("    return const_cast<char*>(s_errors[errnum]);");
  lines.push("  }");
  lines.push(`  memcpy(__get_local_buffer_data(), "${unkErrorStr}", ${unkErrorStr.length + 1});`);
  /* TODO: Unknown error + atoi(errnum) */
  lines.push("  return __get_local_buffer_data();");
  lines.push("}");
  lines.push('extern "C" __ATTR_ALIAS(__strerror, strerror) __ATTR_WEAK;');
  lines.push("");

  await ctx.fs.linesSaveTo(output, lines);
}
