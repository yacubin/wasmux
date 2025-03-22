const fs = require("node:fs");
const path = require("node:path");

const cxx = require("bitmake/utils/CXX.js");

module.exports = function({input, output})
{
  const config = require(input);
  const syscalls = Object.entries(config).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = cxx.filepathToMacroCIdentifier(output);

  const lines = [];

  lines.push(cxx.generatedScriptNameComment(__filename));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  for (const [name, {number}] of syscalls) {
    lines.push(`#define SYS_${name} ${number}`);
  }

  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push(``);

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
