export default (mk) => {
  if (mk.WASMUX_KERNEL) {
    mk.addSubdirectory("waml");
    mk.addSubdirectory("jsdata");
    mk.addSubdirectory("walinuz");
  }
}
