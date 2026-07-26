import path from "node:path";
import fs from "node:fs";
import url from "node:url";

const [ ,, input, output ] = process.argv;

const configUrl = url.pathToFileURL(input);
const config = (await import(configUrl)).default;
const syscalls = Object.entries(config).filter(([name, {func}]) => !!func).sort((a, b) => a[1].number - b[1].number);

const lines = [];

const pragmaOnce = "_WASMUX_ARCH_ARCH_SYSCALL_H";

lines.push("");
lines.push(`#ifndef ${pragmaOnce}`);
lines.push(`#define ${pragmaOnce}`);
lines.push("");
lines.push("#ifdef __cplusplus");
lines.push('extern "C" {');
lines.push("#endif");
lines.push("");

const args6 = [ 1, 2, 3, 4, 5, 6 ];
const passArgs6 = args6.map(i => "a" + i);
const declareArgs6 = passArgs6.map(i => "long " + i);

for (const [name, {argc, func}] of syscalls) {
  const declareArgs = declareArgs6.slice(0, argc).join(", ") || "void";
  lines.push(`long __seal_${func}(${declareArgs});`);
}

lines.push("");

for (const [name, {func}] of syscalls) {
  lines.push(`#define __SEAL_${name} __seal_${func}`);
}

lines.push("");
lines.push("#ifdef __cplusplus");
lines.push("}");
lines.push("#endif");
lines.push("");
lines.push(`#endif /* ${pragmaOnce} */`);
lines.push("");

await fs.promises.mkdir(path.dirname(output), { recursive: true });
await fs.promises.writeFile(output, lines.join('\n'), "utf8");
