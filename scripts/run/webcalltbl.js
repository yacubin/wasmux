const path = require('path');
const fs = require('fs');

const { loadWebcalls } = require('../utils/LoadWebcalls.js');

async function runScript(side, input, output)
{
  const webcalls = await loadWebcalls(input, side);

  let lines = [];

  let index = 0;
  for (const name of webcalls)
    lines.push(`__WEBCALL(${index++}, ${name})`);

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}

runScript(...process.argv.slice(2)).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
