import path from 'node:path';
import { createRequire } from 'node:module';

const require = createRequire(import.meta.url);
const mainPath = require.resolve(process.argv[2]);
const result = path.dirname(mainPath);

process.stdout.write(result);
