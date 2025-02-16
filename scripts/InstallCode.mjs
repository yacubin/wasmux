import { InjectContext } from "###/inject/InjectContext.mjs";

export default async function({script, configScript, pluginList})
{
  const ctx = new InjectContext(script);

  await ctx.loadPlugins();
  await ctx.initPlugins();
  
  console.log("Hello Install code");
}
