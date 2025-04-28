import fs from "node:fs";
import path from "node:path";

import bitmake from "bitmake";
const { cxx } = bitmake;

export default async function(mk, {input, output})
{
  const syscalls = (await import(input)).default;

  const lines = [];
  const pragmaOnce = cxx.filenameToPragmaOnceMacro(output);

  lines.push(cxx.generatedScriptNameComment(import.meta.url));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  let maxNumber = 0;
  for (const [ name, { number }] of Object.entries(syscalls)) {
    lines.push(`#define __NR_${name} ${number}`);
    maxNumber = Math.max(maxNumber, number);
  }

  lines.push(``);
  lines.push(`#ifdef __KERNEL__`);
  lines.push(`#define __NR_syscalls ${maxNumber + 1}`);
  lines.push(`#endif`);
  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
