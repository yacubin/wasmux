const fs = require("node:fs");
const path = require("node:path");

const { loadWebcalls } = require("###/LoadWebcalls.js");

module.exports = function({input, output})
{
  const webcalls = loadWebcalls(input, "main");

  let lines = [];
  for (let i = 0; i < webcalls.length; i++)
    lines.push(`__WEBCALL(${i}, ${webcalls[i]})`);

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
