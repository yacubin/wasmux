const url = require('url');
const path = require('path');

function toArray(o)
{
  if (o === undefined)
    return [];
  return Array.isArray(o) ? o : [o];
}

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
      lines.push(`set(WASMUX_INSTALL_BINDIR "${ctx.global.install.binDir}")`);
      lines.push(`set(WASMUX_INSTALL_LIBDIR "${ctx.global.install.libDir}")`);
      lines.push(`set(WASMUX_INSTALL_INCLUDEDIR "${ctx.global.install.includeDir}")`);
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
        const module = await import(url.pathToFileURL(filename));
        const target = module.default;
        const { name } = target;

        const env = {
          sourceDir: ctx.path.dirname(filename),
          binaryDir: ctx.path.resolve(ctx.global.binaryDir, name),
        };
        let { entry } = target;
        if (typeof entry === "function")
          entry = entry(ctx, env);
        if (entry instanceof Promise)
          await entry;

        const cmakeResolve = (filename) => {
          const prefix = path.isAbsolute(filename) ? "" : env.sourceDir;
          const fullname = path.posix.resolve(prefix, filename);
          const resolvePath = path.relative(ctx.global.sourceDir, fullname);
          return resolvePath.startsWith(".") ? fullname : resolvePath;
        };

        const privateHeaders = [];
        if (entry.private?.headers) {
          for (const filename of entry.private.headers)
            privateHeaders.push(cmakeResolve(filename));
        }

        lines.push(`set(${name}_HEADERS`);
        for (const filename of privateHeaders)
          lines.push(`  "${filename}"`);
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_SOURCES`);
        if (entry.private?.sources) {
          for (const filename of entry.private.sources)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_INCLUDES`);
        if (entry.private?.includes) {
          for (const filename of entry.private.includes)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_PUBLIC_INCLUDES`);
        if (entry.public?.includes) {
          for (const filename of entry.public.includes)
            lines.push(`  "${cmakeResolve(filename)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_PUBLIC_LIBRARIES`);
        if (entry.public?.libraries) {
          for (const library of entry.public.libraries)
            lines.push(`  "${library}"`);
        }
        lines.push(`  )`);
        lines.push('');

        lines.push(`set(${name}_GENFILES`);
        if (entry.private?.genfiles) {
          for (const { output } of entry.private.genfiles)
            lines.push(`  "${cmakeResolve(output)}"`);
        }
        lines.push(`  )`);
        lines.push('');

        if (entry.private?.genfiles) {
          for (const iter of entry.private.genfiles) {
            lines.push('add_custom_command(COMMAND "${NODE_EXECUTABLE}"');
            lines.push(`    "${iter.script}"`);
            for (const arg of iter.args)
              lines.push(`    "${arg}"`);
            lines.push('  DEPENDS');
            lines.push(`    "${iter.script}"`);
            lines.push(`    "${iter.input}"`);
            lines.push('  OUTPUT');
            lines.push(`    "${iter.output}"`);
            lines.push('  WORKING_DIRECTORY');
            lines.push(`    "${iter.workDir}"`);
            lines.push('  VERBATIM');
            lines.push('  )');
            lines.push('');
          }
        }

        lines.push(`make_directory(${env.binaryDir})`);
        lines.push('');

        lines.push(`add_library(${name} STATIC \${${name}_HEADERS} \${${name}_SOURCES} \${${name}_GENFILES})`);
        lines.push(`target_include_directories(${name} PUBLIC \${${name}_PUBLIC_INCLUDES})`);
        lines.push(`target_include_directories(${name} PRIVATE \${${name}_INCLUDES})`);
        lines.push(`target_link_libraries(${name} PUBLIC \${${name}_PUBLIC_LIBRARIES})`);
        lines.push(`set_target_properties(${name} PROPERTIES LINKER_LANGUAGE CXX)`);
        lines.push('');

        if (entry.install?.headers) {
          lines.push('if (CONFIG_ENABLE_INSTALL_HEADERS)');
          for (const iter of toArray(entry.install.headers)) {
            for (const filename of toArray(iter.files)) {
              const dst =  ctx.path.dirname(ctx.path.relative(iter.baseDir, filename));
              lines.push(`  install(FILES "${cmakeResolve(filename)}" DESTINATION "${ctx.path.join(ctx.global.install.includeDir, dst)}")`);
            }
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
