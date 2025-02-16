const path = require('path');
const fs = require('fs');
const url = require('url');

const { filepathToMacroCIdentifier } = require('../utils/CXX.js');
const { generatedScriptNameComment } = require('../utils/CXX.js');

module.exports = async function(ctx)
{
  const {input, output} = ctx.args;

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

  lines.push(generatedScriptNameComment(process.argv[1]));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  for (const [name, {number}] of syscalls) {
    lines.push(`#define SYS_${name} ${number}`);
  }

  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push(``);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'));
}
