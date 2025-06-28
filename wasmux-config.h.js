const fs = require("node:fs");
const { cxx } = require("bitmake");

module.exports = (mk) => {
  const lines = [];

  lines.push(cxx.generatedScriptNameComment(__filename));
  lines.push("");

  for (const [name, entry] of Object.entries(mk.SCRIPT_INPUT)) {
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
      throw new Error(`"${name}" has ${entry.value} value`);
    }
    lines.push("");
  }

  fs.mkdirSync(mk.SCRIPT_OUTPUT.dirname().toString(), { recursive: true });
  fs.writeFileSync(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
