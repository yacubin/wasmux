import { InjectContext } from "###/inject/InjectContext.mjs";

export default async function({script, input, pluginList, outputHeader, outputObject, outputScript, print})
{
  if (!input) {
    throw "Not pass the input filename to the program";
  }

  const ctx = new InjectContext(script);
  ctx.loadInitConfig(input);

  if (pluginList) {
    for (const filename of pluginList.split(";")) {
      await ctx.loadPlugin(filename);
    }
  }

  await ctx.initPlugins();
  await ctx.triggerInitConfig();

  if (outputScript) {
    await ctx.saveInitConfigAsCMake(outputScript, print);
  }

  if (outputHeader) {
    await ctx.saveInitConfigAsCHeader(outputHeader);
  }

  if (outputObject) {
    await ctx.saveInitConfigAsModule(outputObject);
  }
}
