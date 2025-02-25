export default {
  walinuz: {
    depends: "WASMUX_ENABLE_KERNEL",
    objlibs: {
      jsdata:    { cmakeDir: "jsdata"    },
    },
  },
};
