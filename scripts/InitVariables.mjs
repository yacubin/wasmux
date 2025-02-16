import { InjectContext } from "###/inject/InjectContext.mjs";

export default async function({script, input, pluginList, outputHeader, outputObject, outputScript, print})
{
  if (!input) {
    throw "Not pass the input filename to the program";
  }

  const ctx = new InjectContext(script);

  if (pluginList) {
    for (const filename of pluginList.split(";")) {
      await ctx.loadPlugin(filename);
    }
  }

  await ctx.initPlugins();

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
