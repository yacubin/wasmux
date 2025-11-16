import fs from "node:fs";
import bitmake from "bitmake";

export default async function(mk) {
  const lines = [];

  lines.push(bitmake.cxx.generatedScriptNameComment(import.meta.filename));
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
    else if (bitmake.Locator.isLocator(entry.value)) {
      lines.push(`#define ${name} "${entry.value.toPath()}"`);
    }
    else if (Array.isArray(entry.value)) {
      lines.push(`#define ${name} "${entry.value.join(";")}"`);
    }
    else {
      throw new Error(`"${name}" has ${JSON.stringify(entry.value)} value`);
    }
    lines.push("");
  }

  await fs.promises.mkdir(mk.SCRIPT_OUTPUT.dirname().toPath(), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toPath(), lines.join('\n'), "utf8");
}
