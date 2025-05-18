import fs from "node:fs";
import url from "node:url";
import bitmake from "bitmake";

export default async function(mk) {
  const configUrl = url.pathToFileURL(mk.SCRIPT_INPUT.toString());
  const config = (await import(configUrl)).default;
  const syscalls = Object.entries(config).filter(([name, {func}]) => !!func).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = bitmake.cxx.filenameToPragmaOnceMacro(mk.SCRIPT_OUTPUT.toString());

  const lines = [];

  lines.push(bitmake.cxx.generatedScriptNameComment(import.meta.url));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push("");
  lines.push("#ifdef __cplusplus");
  lines.push('extern "C" {');
  lines.push("#endif");
  lines.push("");

  const args6 = [ 1, 2, 3, 4, 5, 6 ];
  const passArgs6 = args6.map(i => "a" + i);
  const declareArgs6 = passArgs6.map(i => "long " + i);

  for (const [name, {argc, func}] of syscalls) {
    const declareArgs = declareArgs6.slice(0, argc).join(", ") || "void";
    lines.push(`long __seal_${func}(${declareArgs});`);
  }

  lines.push("");

  for (const [name, {func}] of syscalls) {
    lines.push(`#define __SEAL_${name} __seal_${func}`);
  }

  lines.push("");
  lines.push("#ifdef __cplusplus");
  lines.push("}");
  lines.push("#endif");
  lines.push("");
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push("");

  await fs.promises.mkdir(mk.SCRIPT_OUTPUT.dirname().toString(), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
