export default async function(ctx)
{
  const {input, output} = ctx.args;

  if (!input) {
    throw "Not pass the binary dir";
  }
  if (!output) {
    throw "Not pass the output";
  }

  await ctx.errno.loadConfig(input);
  await ctx.errno.triggerEvent();
  await ctx.errno.saveHeader(output);
}
