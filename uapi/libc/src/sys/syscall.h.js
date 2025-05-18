const fs = require("node:fs");
const path = require("node:path");

const { cxx } = require("bitmake");

module.exports = function(mk)
{
  const config = require(mk.SCRIPT_INPUT.toString());
  const syscalls = Object.entries(config).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = cxx.filenameToPragmaOnceMacro(mk.SCRIPT_OUTPUT.toString());

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

  fs.mkdirSync(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  fs.writeFileSync(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
