const path = require('path');
const fs = require('fs');

async function runScript(input, output)
{
  if (!input) {
    throw "Not pass the input filename to the program";
  }
  if (!output) {
    throw "Not pass the output filename to the program";
  }

  const content = await fs.promises.readFile(input, 'utf-8');
  const syscalls = Object.entries(JSON.parse(content)).sort((a, b) => a[1].number - b[1].number);

  const lines = [ "/* Automatically generated file (DO NOT EDIT) */" ];

  lines.push(`#ifndef _WA_KERNEL_SYSCALL_NUMS_H`);
  lines.push(`#define _WA_KERNEL_SYSCALL_NUMS_H`);
  lines.push(``);

  for (const [name, {number}] of syscalls) {
    lines.push(`#define SYS_${name} ${number}`);
  }

  lines.push(``);
  lines.push(`#endif /* _WA_KERNEL_SYSCALL_NUMS_H */`);
  lines.push(``);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'));
}

runScript(...process.argv.slice(2)).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
