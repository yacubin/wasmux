import { fileExists } from "###/utils/FileSystem.js";

export default async function(ctx)
{
  const {sourceDir, binaryDir, output} = ctx.args;

  if (!sourceDir) {
    throw "Not pass the source dir";
  }
  if (!binaryDir) {
    throw "Not pass the binary dir";
  }
  if (!output) {
    throw "Not pass the output";
  }

  const indexPath = ctx.path.join(sourceDir, "index.mjs");
  if (await fileExists(indexPath)) {
    await ctx.libraries.loadIndex(indexPath);
  }

  await ctx.libraries.triggerEvent();
  await ctx.libraries.saveSubdirEntry(output);
}
