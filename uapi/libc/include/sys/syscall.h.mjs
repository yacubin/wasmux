import path from "node:path";
import fs from "node:fs";
import url from "node:url";

const [ ,, input, output ] = process.argv;

const configUrl = url.pathToFileURL(input);
const config = (await import(configUrl)).default;
const syscalls = Object.entries(config).filter(([name, {func}]) => !!func).sort((a, b) => a[1].number - b[1].number);

const lines = [];

const pragmaOnce = "_SYS_SYSCALL_H";

lines.push(`#ifndef ${pragmaOnce}`);
lines.push(`#define ${pragmaOnce}`);
lines.push("");

for (const [name, {number}] of syscalls) {
  lines.push(`#define SYS_${name} ${number}`);
}

lines.push("");
lines.push(`#endif /* ${pragmaOnce} */`);
lines.push("");

await fs.promises.mkdir(path.dirname(output), { recursive: true });
await fs.promises.writeFile(output, lines.join('\n'), "utf8");
