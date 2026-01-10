import fs from "node:fs";
import bitmake from "bitmake";

export default async (mk) => {
  const lines = [];

  lines.push(bitmake.cxx.generatedScriptNameComment(import.meta.url));
  switch (mk.SYSTEM_PROCESSOR) {
  case 'wasm32':
  case 'wasm64':
    lines.push(`.section  .custom_section.${mk.SCRIPT_SECTION},"",@`);
    break;
  case 'i686':
    lines.push(`.section  ${mk.SCRIPT_SECTION},""`);
    break;
  default:
    throw `Unknown '${mk.SYSTEM_PROCESSOR}' cpu name`;
  }

  const buffer = await fs.promises.readFile(mk.SCRIPT_INPUT.toString());

  let line = '';
  for (let i = 0; i < buffer.length; i++) {
    let prefix = '0x';
    if ((i % 16) === 0) {
      line && lines.push(line);
      line = '';
    }
    else if ((i % 8) === 0) {
      prefix = " " + prefix;
    }
    prefix = (line ? ',' : '  .byte  ') + prefix;
    line += prefix + buffer[i].toString(16).toLowerCase().padStart(2, '0');
  }
  line && lines.push(line);
  lines.push('');

  await fs.promises.mkdir(mk.SCRIPT_OUTPUT.dirname().toString(), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
