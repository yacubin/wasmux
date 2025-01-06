const fs = require('fs');

async function pathExists(path)
{
  try {
    return !!(await fs.promises.stat(path));
  } catch {
    return false;
  }
}

function pathExistsSync(path)
{
  try {
    return !!fs.statSync(path);
  } catch {
    return false;
  }
}

async function fileExists(path)
{
  try {
    return (await fs.promises.stat(path)).isFile();
  } catch {
    return false;
  }
}

function fileExistsSync(path)
{
  try {
    return fs.statSync(path).isFile();
  } catch {
    return false;
  } 
}

async function directoryExists(path)
{
  try {
    return (await fs.promises.stat(path)).isDirectory();
  } catch {
    return false;
  }
}

function directoryExistsSync(path)
{
  try {
   return fs.statSync(path).isDirectory();
  } catch {
    return false;
  }
}

module.exports = {
  pathExists,
  pathExistsSync,
  fileExists,
  fileExistsSync,
  directoryExists,
  directoryExistsSync,
};
