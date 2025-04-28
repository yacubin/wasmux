import fs from "node:fs";
import path from "node:path";

import bitmake from "bitmake";
const { cxx } = bitmake;

export default async function(mk, {input, output})
{
  const config = (await import(input)).default;
  const syscalls = Object.entries(config).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = cxx.filenameToPragmaOnceMacro(output);

  const lines = [];

  lines.push(cxx.generatedScriptNameComment(import.meta.url));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  for (const [name, {number}] of syscalls) {
    lines.push(`#define __NR_${name} ${number}`);
  }

  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push(``);

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
