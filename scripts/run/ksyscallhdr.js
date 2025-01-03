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
  const syscalls = Object.entries(JSON.parse(content)).sort((a, b) => a[1] - b[1]);

  const lines = [ "/* Automatically generated file (DO NOT EDIT) */" ];

  lines.push(`#ifndef _WA_UAPI_UNISTD_H`);
  lines.push(`#define _WA_UAPI_UNISTD_H`);
  lines.push(``);

  let maxNumber = 0;
  for (const [name, number] of syscalls) {
    lines.push(`#define __NR_${name} ${number}`);
    maxNumber = Math.max(maxNumber, number);
  }

  lines.push(``);
  lines.push(`#ifdef __KERNEL__`);
  lines.push(`#define __NR_syscalls ${maxNumber + 1}`);
  lines.push(`#endif`);
  lines.push(``);
  lines.push(`#endif /* _WA_UAPI_UNISTD_H */`);
  lines.push(``);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'));
}

runScript(...process.argv.slice(2)).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
