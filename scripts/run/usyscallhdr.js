const path = require('path');
const fs = require('fs');
const url = require('url');

const { filepathToMacroCIdentifier } = require('../utils/CXXHelper.js');
const { generatedScriptNameComment } = require('../utils/CXXHelper.js');

async function runScript(input, output)
{
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

runScript(...process.argv.slice(2)).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
