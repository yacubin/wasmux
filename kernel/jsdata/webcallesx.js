const fs = require("node:fs");
const path = require("node:path");
const { cxx } = require("bitmake");

const { loadWebcalls } = require("###/LoadWebcalls.js");

module.exports = function(mk, {side})
{
  const webcalls = loadWebcalls(mk.SCRIPT_INPUT.toString(), side);

  let lines = [];

  lines.push(cxx.generatedScriptNameComment(__filename));
  for (const name of new Set(webcalls))
    lines.push(`import { sys_${name} } from 'src/SystemCalls.mjs';`);
  lines.push('');

  lines.push(`export default [`);
  for (const name of webcalls)
    lines.push(`  sys_${name},`);
  lines.push(`];`);
  lines.push('');

  fs.mkdirSync(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  fs.writeFileSync(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
