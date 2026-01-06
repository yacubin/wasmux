const fs = require("node:fs");
const path = require("node:path");

const { cxx } = require("bitmake");
const { loadWebcalls } = require("###/LoadWebcalls.js");

module.exports = function(mk)
{
  const webcalls = loadWebcalls(mk.SCRIPT_INPUT.toString(), 'both');

  let lines = [];

  const pragmaOnce = cxx.filenameToPragmaOnceMacro(mk.SCRIPT_OUTPUT.toString());

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
    lines.push(`#define __WEB_NR_${suffix} ${11+i++}`);
  }

  lines.push('');
  lines.push(`#endif /* ${pragmaOnce} */`);

  fs.mkdirSync(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  fs.writeFileSync(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
