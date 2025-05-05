import fs from "node:fs";
import bitmake from "bitmake";

export default async function(mk) {
  const config = (await import(mk.SCRIPT_INPUT.toString())).default;
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
