const fs = require("node:fs");
const path = require("node:path");

const CXX = require("###/utils/CXX.js");

module.exports = ({input, output}) => {
  const lines = [];

  lines.push(CXX.generatedScriptNameComment(__filename));
  lines.push("");

  for (const [name, entry] of Object.entries(input)) {
    if (entry.description) {
      lines.push(`/* ${entry.description} */`);
    }
    if (typeof entry.value === "boolean") {
      lines.push(`#define ${name} ${entry.value ? 1 : 0}`);
    }
    else if (typeof entry.value === "number") {
      lines.push(`#define ${name} ${entry.value}`);
    }
    else if (typeof entry.value === "string") {
      lines.push(`#define ${name} "${entry.value}"`);
    }
    else if (Array.isArray(entry.value)) {
      lines.push(`#define ${name} "${entry.value.join(";")}"`);
    }
    else {
      throw `Not supported value of ${entry.value}`;
    }
    lines.push("");
  }

  fs.mkdirSync(path.dirname(output), { recursive: true });
  fs.writeFileSync(output, lines.join('\n'), "utf8");
}
