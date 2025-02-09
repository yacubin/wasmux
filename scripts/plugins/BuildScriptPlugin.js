const url = require('url');
const path = require('path');

class BuildScriptPlugin {
  _filename;

  constructor(options)
  {
    this._filename = options.filename;
  }

  apply(ctx)
  {
    ctx.addProcessAssets(async () => {
      let lines = [];
    
      lines.push('list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")');
      lines.push('');
      lines.push('set(WASMUX_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")');
      lines.push('');
      lines.push('include(WxMacros)');
      lines.push('include(GenScript)');
      lines.push('');
    
      for (const [key,val] of Object.entries(ctx.settings)) {
        const space = val.dependency ? "  " : "";
        if (val.dependency) {
          lines.push(`if (${val.dependency})`);
        }
        if (Array.isArray(val.type)) {
          const strings = val.type.map((i) => '"' + i + '"').join(' ');
          lines.push(`${space}set(${key} "${val.value}" CACHE STRING "${val.description}")`);
          lines.push(`${space}set_property(CACHE ${key} PROPERTY STRINGS ${strings})`);
        }
        else if (val.type === "boolean" || (val.type === undefined && typeof val.value === "boolean")) {
          lines.push(`${space}option(${key} "${val.description}" ${val.value ? "ON" : "OFF"})`);
        }
        else if (val.type === "number" || (val.type === undefined && typeof val.value === "number")) {
          lines.push(`${space}set(${key} ${val.value} CACHE STRING "${val.description}")`);
        }
        else if (val.type === "string" || (val.type === undefined && typeof val.value === "string")) {
          lines.push(`${space}set(${key} "${val.value}" CACHE STRING "${val.description}")`);
        }
        else {
          throw `Unknown variable type: ${val.type}`;
        }
        if (val.dependency) {
          lines.push(`endif ()`);
        }
      }
    
      lines.push('');
      lines.push(`set(WASMUX_INSTALL_BINDIR "${ctx.variables.install.binDir}")`);
      lines.push(`set(WASMUX_INSTALL_LIBDIR "${ctx.variables.install.libDir}")`);
      lines.push(`set(WASMUX_INSTALL_INCLUDEDIR "${ctx.variables.install.includeDir}")`);
      lines.push('');
      lines.push('if (CONFIG_TARGET_SYSTEM MATCHES "-wasi$")');
      lines.push('  set(WASMUX_INSTALL_LIBDIR "${WASMUX_INSTALL_LIBDIR}/${CMAKE_SYSTEM_PROCESSOR}-wasi")');
      lines.push('endif ()');
      lines.push('');
      lines.push('set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -D__ASSEMBLY__")');
      lines.push('');
      lines.push('configure_file(config.h.cmake "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)');
      lines.push('include_directories("${CMAKE_CURRENT_BINARY_DIR}")');
      lines.push('');

      for (const filename of ctx.targets) {
        const currentDir = path.posix.dirname(filename);
        const module = await import(url.pathToFileURL(filename));
        const target = module.default;
        const { name } = target;

        const cmakeResolve = (filename) => {
          const prefix = path.isAbsolute(filename) ? "" : currentDir;
          const fullname = path.posix.resolve(prefix, filename);
          const resolvePath = path.relative(ctx.variables.sourceDir, fullname);
          return resolvePath.startsWith(".") ? fullname : resolvePath;
        };

        lines.push(`set(${name}_HEADERS`);
        if (target.private?.headers) {
          for (const filename of target.private.headers)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_SOURCES`);
        if (target.private?.sources) {
          for (const filename of target.private.sources)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_INCLUDES`);
        if (target.private?.includes) {
          for (const filename of target.private.includes)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_PUBLIC_INCLUDES`);
        if (target.public?.includes) {
          for (const filename of target.public.includes)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`add_library(${name} STATIC \${${name}_HEADERS} \${${name}_SOURCES})`);
        lines.push(`target_include_directories(${name} PUBLIC \${${name}_PUBLIC_INCLUDES})`);
        lines.push(`target_include_directories(${name} PRIVATE \${${name}_INCLUDES})`);
        lines.push(`set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)`);
        lines.push('');

        if (target.install?.headers) {
          lines.push('if (CONFIG_ENABLE_INSTALL_HEADERS)');
          for (const filename of target.install.headers.files) {
            const src = path.posix.resolve(path.isAbsolute(filename) ? "" : currentDir, filename);
            const dst =  path.posix.dirname(path.posix.relative(target.install.headers.baseDir, filename));
            lines.push(`  install(FILES "${src}" DESTINATION "${path.posix.join(ctx.variables.install.includeDir, dst)}")`);
          }
          lines.push('endif ()');
          lines.push('');
        }
      }

      lines.push('add_subdirectory(waf)');
      lines.push('add_subdirectory(uapi)');
      lines.push('add_subdirectory(kernel)');
      lines.push('add_subdirectory(tools)');
      lines.push('');

      ctx.assets[this._filename] = lines.join('\n');
    });
  }
};

module.exports = BuildScriptPlugin;
