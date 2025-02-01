const path = require('path');
const fs = require('fs');

const { generatedScriptNameComment } = require('../utils/CXXHelper.js');

async function runScript(cpu,section,input,output)
{
  console.log(`cpu = ${cpu}, section = ${section}, input = ${input}, output = ${output}`)

  let lines = [];

  lines.push(generatedScriptNameComment(process.argv[1]));
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

  const buffer = await fs.promises.readFile(input);

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

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}

runScript(...process.argv.slice(2)).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
