export default async function(ctx)
{
  const {input, outputHeader, outputObject, outputScript, print} = ctx.args;

  if (!input) {
    throw "Not pass the input filename to the program";
  }

  await ctx.variables.loadConfig(input);
  await ctx.variables.triggerEvent();

  if (outputScript) {
    await ctx.variables.saveInitConfigAsCMake(outputScript, print);
  }

  if (outputHeader) {
    await ctx.variables.saveInitConfigAsCHeader(outputHeader);
  }

  if (outputObject) {
    await ctx.variables.saveInitConfigAsModule(outputObject);
  }
}
