import path from "node:path";
import fs from "node:fs";

const [ ,, input, output ] = process.argv;

const content = await fs.promises.readFile(input, "utf8");
const errors = JSON.parse(content).sort((a, b) => a.code - b.code);

let maxNameLength = Math.max(...errors.map(i => i.name.length));
let maxCodeLength = Math.max(...errors.map(i => i.code.toString().length));
let nameSpace = " ".repeat(maxNameLength);
let codeSpace = " ".repeat(maxCodeLength);

const lines = [];

const pragmaOnce = "_WASMUX_ERRNO_H";

lines.push(`#ifndef ${pragmaOnce}`);
lines.push(`#define ${pragmaOnce}`);
lines.push("");
for (const {name, code, message} of errors) {
  const text = `#define ${name}${nameSpace.substring(name.length)}  ${code}`;
  lines.push(text + (message ? `  ${codeSpace.substring(code.toString().length)}  /* ${message} */` : ""));
}
lines.push("");
lines.push(`#define ENOTSUP      EOPNOTSUPP`);
lines.push(`#define ENOATTR      ENODATA`);
lines.push(`#define EWOULDBLOCK  EAGAIN`);
lines.push("");
lines.push(`#endif /* ${pragmaOnce} */`);
lines.push("");

await fs.promises.mkdir(path.dirname(output), { recursive: true });
await fs.promises.writeFile(output, lines.join('\n'), "utf8");
