import { filepathToMacroCIdentifier } from "###/utils/CXX.js";
import { generatedScriptNameComment } from "###/utils/CXX.js";
import { loadWebcalls } from '###/utils/LoadWebcalls.js';

export const ARGS = {
  INPUT:  { type: "string", name: "input"  },
  OUTPUT: { type: "string", name: "output" },
};

export default async function(ctx)
{
  const {input, output} = ctx.args;

  const webcalls = await loadWebcalls(input, 'both');

  let lines = [];

  const pragmaOnce = filepathToMacroCIdentifier(output);

  lines.push(generatedScriptNameComment(process.argv[1]));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push('');

  let maxLenght = 0;
  for (const name of webcalls)
    maxLenght = Math.max(maxLenght, name.length);

  let i = 0;
  for (const name of webcalls) {
    const suffix = name.padEnd(maxLenght, ' ');
    lines.push(`#define __WEB_NR_${suffix} ${i++}`);
  }

  lines.push('');
  lines.push(`#endif /* ${pragmaOnce} */`);

  await ctx.fs.linesSaveTo(output, lines);
}
