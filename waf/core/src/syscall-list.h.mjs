import fs from "node:fs";
import path from "node:path";

export default async (mk) => {
  const syscalls = (await import(mk.SCRIPT_INPUT.toString())).default;

  const lines = [];
  let nextNumber = 0;
  for (const { number, argc, func } of Object.values(syscalls)) {
    while (nextNumber < number)
      lines.push(`__SYSCALL(${nextNumber++}, x, sys_ni_syscall)`);
    if (func === null)
      lines.push(`__SYSCALL(${number}, x, sys_ni_syscall)`);
    else
      lines.push(`__SYSCALL(${number}, ${argc}, ${func})`);
      nextNumber = number + 1;
  }

  await fs.promises.mkdir(path.dirname(mk.SCRIPT_OUTPUT.toString()), { recursive: true });
  await fs.promises.writeFile(mk.SCRIPT_OUTPUT.toString(), lines.join('\n'), "utf8");
}
