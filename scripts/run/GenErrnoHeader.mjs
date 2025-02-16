import url from 'node:url';
import * as CXX from "###/utils/CXX.js";

export default async function(ctx)
{
  const {input, output} = ctx.args;

  if (!input) {
    throw "Not pass the binary dir";
  }

  if (!output) {
    throw "Not pass the output";
  }

  const inputUrl = url.pathToFileURL(input);
  const module = await import(inputUrl);

  const config = {
    errors: module.errors || {},
    aliases: module.aliases || {},
  };

  ctx.hooks.emit("errno.config", config);

  let errors = [];
  let aliases = [];

  let maxNameLength = 0;
  let maxCodeLength = 0;
  for (const [name, entry] of Object.entries(config.errors)) {
    maxNameLength = Math.max(maxNameLength, name.length);
    maxCodeLength = Math.max(maxCodeLength, entry.code.toString().length);
    errors.push({ name, ...entry });
  }

  for (const [name, alias] of Object.entries(config.aliases)) {
    maxNameLength = Math.max(maxNameLength, name.length);
    const entry = config.errors[alias];
    aliases.push({ name, ...entry, alias });
  }

  let nameSpace = " ".repeat(maxNameLength);
  let codeSpace = " ".repeat(maxNameLength);
  errors = errors.sort((a, b) => a.code - b.code);
  aliases = aliases.sort((a, b) => a.code - b.code);

  const lines = [];

  const pragmaOnce = CXX.filepathToMacroCIdentifier(output);
  lines.push(CXX.generatedScriptNameComment(ctx.entryScript));
  lines.push("");
  lines.push(`#ifndef ${pragmaOnce}`);
  lines.push(`#define ${pragmaOnce}`);
  lines.push("");
  for (const {name, code, description} of errors) {
    const desc = description ? `/* ${description} */` : "";
    lines.push(`#define ${name}${nameSpace.substring(name.length)} ${code} ${codeSpace.substring(code.length)}${desc}`);
  }
  lines.push("");
  for (const {name, alias} of aliases) {
    const desc = alias.description ? `/* ${alias.description} */` : "";
    lines.push(`#define ${name}${nameSpace.substring(name.length)} ${alias}${desc}`);
  }
  lines.push("");
  lines.push(`#endif /* ${pragmaOnce} */`);
  lines.push("");

  await ctx.fs.linesSaveTo(output, lines);
}
