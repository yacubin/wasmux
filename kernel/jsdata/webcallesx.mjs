import fs from "node:fs";
import bitmake from "bitmake";

import { loadWebcalls } from "###/LoadWebcalls.js";

export default async (mk) => {
  const webcalls = loadWebcalls(mk.SCRIPT_INPUT.toString(), mk.SCRIPT_SIDE);

  let lines = [];

  lines.push(bitmake.cxx.generatedScriptNameComment(import.meta.url));
  for (const name of new Set(webcalls))
    lines.push(`import { sys_${name} } from 'src/SystemCalls.mjs';`);
  lines.push('');

  lines.push(`export default [`);
  for (const name of webcalls)
    lines.push(`  sys_${name},`);
  lines.push(`];`);
  lines.push('');

  await fs.promises.mkdir(mk.SCRIPT_OUTPUT.dirname().toString(), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
