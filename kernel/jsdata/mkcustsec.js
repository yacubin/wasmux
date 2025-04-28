const fs = require("node:fs");
const path = require("node:path");
const { cxx } = require("bitmake");

module.exports = function(mk, {cpu, section, input, output})
{
  const lines = [];

  lines.push(cxx.generatedScriptNameComment(__filename));
  switch (cpu) {
  case 'wasm32':
  case 'wasm64':
    lines.push(`.section  .custom_section.${section},"",@`);
    break;
  case 'i686':
    lines.push(`.section  ${section},""`);
    break;
  default:
    throw `Unknown '${cpu}' cpu name`;
  }

  const buffer = fs.readFileSync(input);

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

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
