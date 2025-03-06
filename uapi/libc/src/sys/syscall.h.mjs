import base from "./syscall.h.js";

export const ARGS = {
  INPUT:  { type: "string", name: "input"  },
  OUTPUT: { type: "string", name: "output" },
};

export default async function(ctx, {input, output})
{
  base({ depends: input, output });
}
