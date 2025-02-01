const path = require('path');
const fs = require('fs');

const { generatedScriptNameComment } = require('../utils/CXXHelper.js');
const { loadWebcalls } = require('../utils/LoadWebcalls.js');

async function runScript(side,input,output)
{
  const webcalls = await loadWebcalls(input, side);

  let lines = [];

  lines.push(generatedScriptNameComment(process.argv[1]));
  for (const name of new Set(webcalls))
    lines.push(`import { sys_${name} } from 'src/SystemCalls.mjs';`);
  lines.push('');

  lines.push(`export default [`);
  for (const name of webcalls)
    lines.push(`  sys_${name},`);
  lines.push(`];`);
  lines.push('');

  await fs.promises.mkdir(path.dirname(output), { recursive: true });
  await fs.promises.writeFile(output, lines.join('\n'), { encoding: "utf8" });
}

runScript(...process.argv.slice(2)).then(() => process.exit(0)).catch((e) => {
  console.error(e);
  process.exit(1);
});
