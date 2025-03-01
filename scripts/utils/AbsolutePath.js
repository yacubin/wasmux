const path = require("node:path");
const url = require("node:url");

class AbsolutePath {
  _filepath;

  constructor(filepath) {
    if (!path.isAbsolute(filepath))
      throw new Error(`Not supported relative path of "${filepath}"`);
    this._filepath = filepath;
  }

  join(...paths) {
    const filepath = path.posix.join(this._filepath, ...paths);
    return new AbsolutePath(filepath);
  }

  dirname() {
    return new AbsolutePath(path.posix.dirname(this._filepath));
  }

  relative(to) {
    if (to instanceof AbsolutePath)
      to = to._filepath;
    const filepath = path.posix.relative(this._filepath, to);
    return filepath;
  }

  toURL() {
    return url.pathToFileURL(this._filepath);
  }

  toURLString() {
    return this.toURL().toString();
  }

  toString() {
    return this._filepath;
  }

  static isAbsolute(filepath) {
    return path.isAbsolute(filepath.toString());
  }
};

module.exports = {
  AbsolutePath,
};
