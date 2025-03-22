const fs = require("node:fs");
const path = require("node:path");

const cxx = require("bitmake/utils/CXX.js");
const { loadWebcalls } = require("bitmake/utils/LoadWebcalls.js");

module.exports = function({input, output})
{
  const webcalls = loadWebcalls(input, 'both');

  let lines = [];

  const pragmaOnce = cxx.filepathToMacroCIdentifier(output);

  lines.push(cxx.generatedScriptNameComment(__filename));
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

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
