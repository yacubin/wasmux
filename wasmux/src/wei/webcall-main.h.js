const fs = require("node:fs");
const path = require("node:path");

const { loadWebcalls } = require("###/LoadWebcalls.js");

module.exports = function(mk)
{
  const webcalls = loadWebcalls(mk.SCRIPT_INPUT.toString(), "main");

  let lines = [];
  for (let i = 0; i < webcalls.length; i++)
    lines.push(`__WEBCALL(${11+i}, ${webcalls[i]})`);

  fs.mkdirSync(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  fs.writeFileSync(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
