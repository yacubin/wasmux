import { fileExists } from "###/utils/FileSystem.js";
import { InjectContext } from "###/inject/InjectContext.mjs";

export default async function({script, configScript, sourceDir, binaryDir, pluginList, output})
{
  if (!sourceDir) {
    throw "Not pass the source dir";
  }
  if (!binaryDir) {
    throw "Not pass the binary dir";
  }
  if (!output) {
    throw "Not pass the output";
  }

  const ctx = new InjectContext;

  if (configScript) {
    await ctx.loadConfig(configScript);
  }

  const indexPath = ctx.path.join(sourceDir, "index.mjs");
  if (await fileExists(indexPath)) {
    await ctx.loadIndex(indexPath);
  }

  if (pluginList) {
    for (const filename of pluginList.split(";")) {
      await ctx.loadPlugin(filename);
    }
  }

  await ctx.initPlugins();
  await ctx.triggerLibraries();
  await ctx.saveSubdirEntry(output);
}
