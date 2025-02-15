import { InjectContext } from "###/inject/InjectContext.mjs";

export default async function({script, configScript, pluginList})
{
  const ctx = new InjectContext(script);

  if (pluginList) {
    for (const filename of pluginList.split(";")) {
      await ctx.loadPlugin(filename);
    }
  }

  await ctx.initPlugins();
  
  console.log("Hello Install code");
}
