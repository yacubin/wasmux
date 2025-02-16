const path = require('path');
const fs = require('fs');

const { generatedScriptNameComment } = require('../utils/CXX.js');
const { loadWebcalls } = require('../utils/LoadWebcalls.js');

module.exports = async function(ctx)
{
  const {side, input, output} = ctx.args;

  const webcalls = await loadWebcalls(input, side);

  let lines = [];

  lines.push(generatedScriptNameComment(ctx.entryScript));
  for (const name of new Set(webcalls))
    lines.push(`import { sys_${name} } from 'src/SystemCalls.mjs';`);
  lines.push('');

  lines.push(`export default [`);
  for (const name of webcalls)
    lines.push(`  sys_${name},`);
  lines.push(`];`);
  lines.push('');

  await ctx.fs.linesSaveTo(output, lines);
}
