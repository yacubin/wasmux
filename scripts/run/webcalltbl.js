const path = require('path');
const fs = require('fs');

const { loadWebcalls } = require('../utils/LoadWebcalls.js');

module.exports = async function({side, input, output})
{
  const webcalls = await loadWebcalls(input, side);

  let lines = [];

  let index = 0;
  for (const name of webcalls)
    lines.push(`__WEBCALL(${index++}, ${name})`);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}
