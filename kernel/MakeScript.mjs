export default (mk) => {
  if (mk.WASMUX_KERNEL) {
    mk.addSubdirectory("jsdata");
    mk.addSubdirectory("kapsule");
  }
}
