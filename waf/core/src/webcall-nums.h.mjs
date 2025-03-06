import base from "./webcall-nums.h.js";

export const ARGS = {
  INPUT:  { type: "string", name: "input"  },
  OUTPUT: { type: "string", name: "output" },
};

export default function(ctx, {input, output})
{
  base({ depends: input, output });
}
