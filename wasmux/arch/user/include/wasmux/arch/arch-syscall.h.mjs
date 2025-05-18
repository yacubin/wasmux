import fs from "node:fs";
import url from "node:url";
import bitmake from "bitmake";

export default async function(mk) {
  const configUrl = url.pathToFileURL(mk.SCRIPT_INPUT.toString());
  const config = (await import(configUrl)).default;
  const syscalls = Object.entries(config).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = bitmake.cxx.filenameToPragmaOnceMacro(mk.SCRIPT_OUTPUT.toString());

  const lines = [];

  lines.push(bitmake.cxx.generatedScriptNameComment(import.meta.url));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  for (const [name, {number}] of syscalls) {
    lines.push(`#define __NR_${name} ${number}`);
  }

  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push(``);

  await fs.promises.mkdir(mk.SCRIPT_OUTPUT.dirname().toString(), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
