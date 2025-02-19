import { generatedScriptNameComment } from "###/utils/CXX.js";
import { loadWebcalls } from "###/utils/LoadWebcalls.js";

export const ARGS = {
  SIDE: {
    type: "string",
    name: "side",
  },
  INPUT: {
    type: "string",
    name: "input",
  },
  OUTPUT: {
    type: "string",
    name: "output",
  },
};

export default async function(ctx, {side, input, output})
{
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
