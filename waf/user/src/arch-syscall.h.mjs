import { filepathToMacroCIdentifier } from "###/utils/CXX.js";
import { generatedScriptNameComment } from "###/utils/CXX.js";

export const ARGS = {
  INPUT:  { type: "string", name: "input"  },
  OUTPUT: { type: "string", name: "output" },
};

export default async function(ctx, {input, output})
{
  const module = await ctx.fs.loadScript(input);
  const syscalls = Object.entries(module.default).sort((a, b) => a[1].number - b[1].number);
  const pragmaOnce = filepathToMacroCIdentifier(output);

  const lines = [];

  lines.push(generatedScriptNameComment(ctx.entryScript));
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push(``);

  for (const [name, {number}] of syscalls) {
    lines.push(`#define __NR_${name} ${number}`);
  }

  lines.push(``);
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push(``);

  await ctx.fs.linesSaveTo(output, lines);
}
