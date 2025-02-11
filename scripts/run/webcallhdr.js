const path = require('path');
const fs = require('fs');

const { filepathToMacroCIdentifier } = require('../utils/CXXHelper.js');
const { generatedScriptNameComment } = require('../utils/CXXHelper.js');
const { loadWebcalls } = require('../utils/LoadWebcalls.js');

module.exports = async function runScript({input, output})
{
  const webcalls = await loadWebcalls(input, 'both');

  let lines = [];

  const pragmaOnce = filepathToMacroCIdentifier(output);

  lines.push(generatedScriptNameComment(process.argv[1]));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push('');

  let maxLenght = 0;
  for (const name of webcalls)
    maxLenght = Math.max(maxLenght, name.length);

  let i = 0;
  for (const name of webcalls) {
    const suffix = name.padEnd(maxLenght, ' ');
    lines.push(`#define __WEB_NR_${suffix} ${i++}`);
  }

  lines.push('');
  lines.push(`#endif /* ${pragmaOnce} */`);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}
