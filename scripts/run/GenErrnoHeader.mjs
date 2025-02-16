import { InjectContext } from "###/inject/InjectContext.mjs";

export default async function({script, configScript, input, output})
{
  if (!input) {
    throw "Not pass the binary dir";
  }
  if (!output) {
    throw "Not pass the output";
  }

  const ctx = new InjectContext(script);

  if (configScript) {
    await ctx.loadConfig(configScript);
  }

  await ctx.loadPlugins();
  await ctx.initPlugins();

  await ctx.errno.loadConfig(input);
  await ctx.errno.triggerEvent();
  await ctx.errno.saveHeader(output);
}
