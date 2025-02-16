const path = require('path');
const fs = require('fs');
const url = require('url');

const { filepathToMacroCIdentifier } = require('../utils/CXX.js');
const { generatedScriptNameComment } = require('../utils/CXX.js');

module.exports = async function(ctx)
{
  const {script, input, output} = ctx.args;

  if (!input) {
    throw "Not pass the input filename to the program";
  }
  if (!output) {
    throw "Not pass the output filename to the program";
  }

  const module = await import(url.pathToFileURL(input));
  const syscalls = Object.entries(module.default).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = filepathToMacroCIdentifier(output);

  const lines = [];

  lines.push(generatedScriptNameComment(script));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  let maxNumber = 0;
  for (const [name, {number}] of syscalls) {
    lines.push(`#define __NR_${name} ${number}`);
    maxNumber = Math.max(maxNumber, number);
  }

  lines.push(``);
  lines.push(`#ifdef __KERNEL__`);
  lines.push(`#define __NR_syscalls ${maxNumber + 1}`);
  lines.push(`#endif`);
  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push(``);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'));
}
