const path = require('path');

function filepathToMacroCIdentifier(filepath, deep)
{
  if (typeof deep === 'undefined')
    deep = 3;

  let components = path.normalize(filepath).split(path.sep);
  if (components.length > deep)
    components = components.slice(components.length - deep);

  return "_" + components.join('_').replace(/[- .:%~]/g, '_').toUpperCase();
}

function generatedScriptNameComment(filename)
{
  return `/* Generated from ${path.basename(filename)} */`;
}

module.exports = {
  filepathToMacroCIdentifier,
  generatedScriptNameComment,
};
