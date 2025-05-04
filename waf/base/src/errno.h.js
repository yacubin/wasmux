const fs = require("node:fs");
const path = require("node:path");

const { cxx } = require("bitmake");

module.exports = function(mk)
{
  const config = require(mk.SCRIPT_INPUT.toString());

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

  const pragmaOnce = cxx.filenameToPragmaOnceMacro(mk.SCRIPT_OUTPUT.toString());
  lines.push(cxx.generatedScriptNameComment(__filename));
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

  fs.mkdirSync(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  fs.writeFileSync(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
