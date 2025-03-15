"use strict";

const { AbsolutePath } = require("###/utils/AbsolutePath.js");

const BUILD_TYPE            = Symbol("BUILD_TYPE");
const DESTDIR               = Symbol("DESTDIR");
const INSTALL_PREFIX        = Symbol("INSTALL_PREFIX");
const SCRIPT_FILE           = Symbol("SCRIPT_FILE");
const SOURCE_DIR            = Symbol("SOURCE_DIR");
const BINARY_DIR            = Symbol("BINARY_DIR");
const ASM_COMPILER          = Symbol("ASM_COMPILER");
const ASM_FLAGS             = Symbol("ASM_FLAGS");
const ASM_FLAGS_DEBUG       = Symbol("ASM_FLAGS_DEBUG");
const ASM_FLAGS_RELEASE     = Symbol("ASM_FLAGS_RELEASE");
const C_COMPILER            = Symbol("C_COMPILER");
const C_FLAGS               = Symbol("C_FLAGS");
const C_FLAGS_DEBUG         = Symbol("C_FLAGS_DEBUG");
const C_FLAGS_RELEASE       = Symbol("C_FLAGS_RELEASE");
const CXX_COMPILER          = Symbol("CXX_COMPILER");
const CXX_FLAGS             = Symbol("CXX_FLAGS");
const CXX_FLAGS_DEBUG       = Symbol("CXX_FLAGS_DEBUG");
const CXX_FLAGS_RELEASE     = Symbol("CXX_FLAGS_RELEASE");
const INCLUDES              = Symbol("INCLUDES");
const STATIC_LIBRARY_PREFIX = Symbol("STATIC_LIBRARY_PREFIX");
const STATIC_LIBRARY_SUFFIX = Symbol("STATIC_LIBRARY_SUFFIX");
const STATIC_LINKER_FLAGS   = Symbol("STATIC_LINKER_FLAGS");
const SHARED_LIBRARY_PREFIX = Symbol("SHARED_LIBRARY_PREFIX");
const SHARED_LIBRARY_SUFFIX = Symbol("SHARED_LIBRARY_SUFFIX");
const SHARED_LINKER_FLAGS   = Symbol("SHARED_LINKER_FLAGS");
const EXECUTABLE_SUFFIX     = Symbol("EXECUTABLE_SUFFIX");
const EXE_LINKER_FLAGS      = Symbol("EXE_LINKER_FLAGS");

function Scope(other) {
  this[BUILD_TYPE]            = other.BUILD_TYPE;
  this[DESTDIR]               = AbsolutePath.create(other.DESTDIR);
  this[INSTALL_PREFIX]        = AbsolutePath.create(other.INSTALL_PREFIX);
  this[SCRIPT_FILE]           = AbsolutePath.create(other.SCRIPT_FILE);
  this[SOURCE_DIR]            = AbsolutePath.create(other.SOURCE_DIR);
  this[BINARY_DIR]            = AbsolutePath.create(other.BINARY_DIR);
  this[ASM_COMPILER]          = other.ASM_COMPILER;
  this[ASM_FLAGS]             = other.ASM_FLAGS;
  this[ASM_FLAGS_DEBUG]       = other.ASM_FLAGS_DEBUG;
  this[ASM_FLAGS_RELEASE]     = other.ASM_FLAGS_RELEASE;
  this[C_COMPILER]            = other.C_COMPILER;
  this[C_FLAGS]               = other.C_FLAGS;
  this[C_FLAGS_DEBUG]         = other.C_FLAGS_DEBUG;
  this[C_FLAGS_RELEASE]       = other.C_FLAGS_RELEASE;
  this[CXX_COMPILER]          = other.CXX_COMPILER;
  this[CXX_FLAGS]             = other.CXX_FLAGS;
  this[CXX_FLAGS_DEBUG]       = other.CXX_FLAGS_DEBUG;
  this[CXX_FLAGS_RELEASE]     = other.CXX_FLAGS_RELEASE;
  this[INCLUDES]              = other.INCLUDES;
  this[STATIC_LIBRARY_PREFIX] = other.STATIC_LIBRARY_PREFIX;
  this[STATIC_LIBRARY_SUFFIX] = other.STATIC_LIBRARY_SUFFIX;
  this[STATIC_LINKER_FLAGS]   = other.STATIC_LINKER_FLAGS;
  this[SHARED_LIBRARY_PREFIX] = other.SHARED_LIBRARY_PREFIX;
  this[SHARED_LIBRARY_SUFFIX] = other.SHARED_LIBRARY_SUFFIX;
  this[SHARED_LINKER_FLAGS]   = other.SHARED_LINKER_FLAGS;
  this[EXECUTABLE_SUFFIX]     = other.EXECUTABLE_SUFFIX;
  this[EXE_LINKER_FLAGS]      = other.EXE_LINKER_FLAGS;
}

Scope.prototype = Object.create(Object.prototype, {
  constructor: {
    value: Scope,
    enumerable: false,
  },
  BUILD_TYPE: {
    get () { return this[BUILD_TYPE]; },
    enumerable: true,
  },
  DESTDIR: {
    get () { return this[DESTDIR]; },
    enumerable: true,
  },
  INSTALL_PREFIX: {
    get () { return this[INSTALL_PREFIX]; },
    enumerable: true,
  },
  SCRIPT_FILE: {
    get () { return this[SCRIPT_FILE]; },
    enumerable: true,
  },
  SOURCE_DIR: {
    get () { return this[SOURCE_DIR]; },
    enumerable: true,
  },
  BINARY_DIR: {
    get () { return this[BINARY_DIR]; },
    enumerable: true,
  },
  ASM_COMPILER: {
    get () { return this[ASM_COMPILER]; },
    enumerable: true,
  },
  ASM_FLAGS: {
    get () { return this[ASM_FLAGS]; },
    enumerable: true,
  },
  ASM_FLAGS_DEBUG: {
    get () { return this[ASM_FLAGS_DEBUG]; },
    enumerable: true,
  },
  ASM_FLAGS_RELEASE: {
    get () { return this[ASM_FLAGS_RELEASE]; },
    enumerable: true,
  },
  C_COMPILER: {
    get () { return this[C_COMPILER]; },
    enumerable: true,
  },
  C_FLAGS: {
    get () { return this[C_FLAGS]; },
    enumerable: true,
  },
  C_FLAGS_DEBUG: {
    get () { return this[C_FLAGS_DEBUG]; },
    enumerable: true,
  },
  C_FLAGS_RELEASE: {
    get () { return this[C_FLAGS_RELEASE]; },
    enumerable: true,
  },
  CXX_COMPILER: {
    get () { return this[CXX_COMPILER]; },
    enumerable: true,
  },
  CXX_FLAGS: {
    get () { return this[CXX_FLAGS]; },
    enumerable: true,
  },
  CXX_FLAGS_DEBUG: {
    get () { return this[CXX_FLAGS_DEBUG]; },
    enumerable: true,
  },
  CXX_FLAGS_RELEASE: {
    get () { return this[CXX_FLAGS_RELEASE]; },
    enumerable: true,
  },
  INCLUDES: {
    get () { return this[INCLUDES]; },
    enumerable: true,
  },
  STATIC_LIBRARY_PREFIX: {
    get () { return this[STATIC_LIBRARY_PREFIX]; },
    enumerable: true,
  },
  STATIC_LIBRARY_SUFFIX: {
    get () { return this[STATIC_LIBRARY_SUFFIX]; },
    enumerable: true,
  },
  STATIC_LINKER_FLAGS: {
    get() { return this[STATIC_LINKER_FLAGS]; },
    enumerable: true,
  },
  SHARED_LIBRARY_PREFIX: {
    get() { return this[SHARED_LIBRARY_PREFIX]; },
    enumerable: true,
  },
  SHARED_LIBRARY_SUFFIX: {
    get() { return this[SHARED_LIBRARY_SUFFIX]; },
    enumerable: true,
  },
  SHARED_LINKER_FLAGS: {
    get() { return this[SHARED_LINKER_FLAGS]; },
    enumerable: true,
  },
  EXECUTABLE_SUFFIX: {
    get() { return this[EXECUTABLE_SUFFIX]; },
    enumerable: true,
  },
  EXE_LINKER_FLAGS: {
    get() { return this[EXE_LINKER_FLAGS]; },
    enumerable: true,
  },
});

Scope.prototype.toJSON = function() {
  const json = {};
  for (const key in this)
    json[key] = this[key];
  return json;
}

Scope.create = function(other) {
  return Object.seal(new Scope(other));
}

module.exports = {
  Scope,
};
