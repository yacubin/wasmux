import url from 'node:url';
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

  let config = {};

  const indexPath = ctx.path.join(sourceDir, "index.mjs");
  if (await fileExists(indexPath)) {
    const fileUrl = url.pathToFileURL(indexPath);
    const module = await import(fileUrl);
    config = module.default;
  }

  for (const [key, val] of Object.entries(config)) {
    await ctx.hooks.emit(`libraries.${key}`, val);
  }

  const lines = [];

  for (const [name, entry] of Object.entries(config)) {
    const space = entry.depends ? "  " : "";
    if (entry.depends) {
      lines.push(`if (${entry.depends})`);
    }
    lines.push(`${space}set(${name}_OBJLIB_LIST "")`);
    if (entry.objlibs) {
      for (const [key, lib] of Object.entries(entry.objlibs)) {
        if (!lib) continue;
        if (key === lib.cmakeDir)
          lines.push(`${space}add_subdirectory(${key})`);
        else
          lines.push(`${space}add_subdirectory("${lib.cmakeDir}" ${key})`);
        lines.push(`${space}list(APPEND ${name}_OBJLIB_LIST ${key})`);
      }
    }
    lines.push(`${space}add_subdirectory(${name})`);
    if (entry.depends) {
      lines.push(`endif ()`);
    }
    lines.push("");
  }

  await ctx.fs.linesSaveTo(output, lines);
}
