import { loadWebcalls } from '###/utils/LoadWebcalls.js';

export const ARGS = {
  INPUT:  { type: "string", name: "input"  },
  OUTPUT: { type: "string", name: "output" },
};

export default async function(ctx, {input, output})
{
  const webcalls = await loadWebcalls(input, "main");

  let lines = [];
  for (let i = 0; i < webcalls.length; i++)
    lines.push(`__WEBCALL(${i}, ${webcalls[i]})`);

  await ctx.fs.linesSaveTo(output, lines);
}
