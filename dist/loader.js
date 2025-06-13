(function webpackUniversalModuleDefinition(root, factory) {
	if(typeof exports === 'object' && typeof module === 'object')
		module.exports = factory();
	else if(typeof define === 'function' && define.amd)
		define([], factory);
	else if(typeof exports === 'object')
		exports["wasmux"] = factory();
	else
		root["wasmux"] = factory();
})(self, () => {
return /******/ (() => { // webpackBootstrap
/******/ 	"use strict";
/******/ 	// The require scope
/******/ 	var __webpack_require__ = {};
/******/ 	
/************************************************************************/
/******/ 	/* webpack/runtime/define property getters */
/******/ 	(() => {
/******/ 		// define getter functions for harmony exports
/******/ 		__webpack_require__.d = (exports, definition) => {
/******/ 			for(var key in definition) {
/******/ 				if(__webpack_require__.o(definition, key) && !__webpack_require__.o(exports, key)) {
/******/ 					Object.defineProperty(exports, key, { enumerable: true, get: definition[key] });
/******/ 				}
/******/ 			}
/******/ 		};
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/hasOwnProperty shorthand */
/******/ 	(() => {
/******/ 		__webpack_require__.o = (obj, prop) => (Object.prototype.hasOwnProperty.call(obj, prop))
/******/ 	})();
/******/ 	
/******/ 	/* webpack/runtime/make namespace object */
/******/ 	(() => {
/******/ 		// define __esModule on exports
/******/ 		__webpack_require__.r = (exports) => {
/******/ 			if(typeof Symbol !== 'undefined' && Symbol.toStringTag) {
/******/ 				Object.defineProperty(exports, Symbol.toStringTag, { value: 'Module' });
/******/ 			}
/******/ 			Object.defineProperty(exports, '__esModule', { value: true });
/******/ 		};
/******/ 	})();
/******/ 	
/************************************************************************/
var __webpack_exports__ = {};
/*!*************************!*\
  !*** ./loader/index.ts ***!
  \*************************/
__webpack_require__.r(__webpack_exports__);
/* harmony export */ __webpack_require__.d(__webpack_exports__, {
/* harmony export */   "default": () => (__WEBPACK_DEFAULT_EXPORT__)
/* harmony export */ });
/*
 * MIT License
 *
 * Copyright (c) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 * Permission is granted to use, copy, modify, and distribute this software
 * under the MIT License. See LICENSE file for details.
 */
;
async function createInstance(moduleUrl) {
    const kresponse = await fetch(moduleUrl);
    const kbuffer = await kresponse.arrayBuffer();
    const kmodule = await WebAssembly.compile(kbuffer);
    const loaderList = WebAssembly.Module.customSections(kmodule, ".jsdata.loader");
    const loaderBlob = new Blob(loaderList, { type: "application/javascript" });
    const loaderUrl = URL.createObjectURL(loaderBlob);
    const { Kernel } = await import(/* webpackIgnore: true */ loaderUrl);
    URL.revokeObjectURL(loaderUrl);
    return new Kernel(kmodule);
}
const defaultContext = Object.assign(createInstance, {});
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (defaultContext);

__webpack_exports__ = __webpack_exports__["default"];
/******/ 	return __webpack_exports__;
/******/ })()
;
});
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoibG9hZGVyLmpzIiwibWFwcGluZ3MiOiJBQUFBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBO0FBQ0E7QUFDQTtBQUNBLENBQUM7QUFDRCxPOztVQ1ZBO1VBQ0E7Ozs7O1dDREE7V0FDQTtXQUNBO1dBQ0E7V0FDQSx5Q0FBeUMsd0NBQXdDO1dBQ2pGO1dBQ0E7V0FDQTs7Ozs7V0NQQTs7Ozs7V0NBQTtXQUNBO1dBQ0E7V0FDQSx1REFBdUQsaUJBQWlCO1dBQ3hFO1dBQ0EsZ0RBQWdELGFBQWE7V0FDN0Q7Ozs7Ozs7Ozs7OztBQ05BOzs7Ozs7O0dBT0c7QUFNRixDQUFDO0FBRUYsS0FBSyxVQUFVLGNBQWMsQ0FBQyxTQUFpQjtJQUM3QyxNQUFNLFNBQVMsR0FBRyxNQUFNLEtBQUssQ0FBQyxTQUFTLENBQUMsQ0FBQztJQUN6QyxNQUFNLE9BQU8sR0FBRyxNQUFNLFNBQVMsQ0FBQyxXQUFXLEVBQUUsQ0FBQztJQUM5QyxNQUFNLE9BQU8sR0FBRyxNQUFNLFdBQVcsQ0FBQyxPQUFPLENBQUMsT0FBTyxDQUFDLENBQUM7SUFFbkQsTUFBTSxVQUFVLEdBQUcsV0FBVyxDQUFDLE1BQU0sQ0FBQyxjQUFjLENBQUMsT0FBTyxFQUFFLGdCQUFnQixDQUFDLENBQUM7SUFDaEYsTUFBTSxVQUFVLEdBQUcsSUFBSSxJQUFJLENBQUMsVUFBVSxFQUFFLEVBQUUsSUFBSSxFQUFFLHdCQUF3QixFQUFFLENBQUMsQ0FBQztJQUU1RSxNQUFNLFNBQVMsR0FBRyxHQUFHLENBQUMsZUFBZSxDQUFDLFVBQVUsQ0FBQyxDQUFDO0lBQ2xELE1BQU0sRUFBRSxNQUFNLEVBQUUsR0FBRyxNQUFNLE1BQU0sQ0FBQyx5QkFBeUIsQ0FBQyxTQUFTLENBQUMsQ0FBQztJQUNyRSxHQUFHLENBQUMsZUFBZSxDQUFDLFNBQVMsQ0FBQyxDQUFDO0lBRS9CLE9BQU8sSUFBSSxNQUFNLENBQUMsT0FBTyxDQUFDLENBQUM7QUFDN0IsQ0FBQztBQUVELE1BQU0sY0FBYyxHQUFHLE1BQU0sQ0FBQyxNQUFNLENBQUMsY0FBYyxFQUFFLEVBQ3BELENBQUMsQ0FBQztBQUVILGlFQUFlLGNBQWMsRUFBQyIsInNvdXJjZXMiOlsid2VicGFjazovL3dhc211eC93ZWJwYWNrL3VuaXZlcnNhbE1vZHVsZURlZmluaXRpb24iLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svYm9vdHN0cmFwIiwid2VicGFjazovL3dhc211eC93ZWJwYWNrL3J1bnRpbWUvZGVmaW5lIHByb3BlcnR5IGdldHRlcnMiLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svcnVudGltZS9oYXNPd25Qcm9wZXJ0eSBzaG9ydGhhbmQiLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svcnVudGltZS9tYWtlIG5hbWVzcGFjZSBvYmplY3QiLCJ3ZWJwYWNrOi8vd2FzbXV4Ly4vbG9hZGVyL2luZGV4LnRzIl0sInNvdXJjZXNDb250ZW50IjpbIihmdW5jdGlvbiB3ZWJwYWNrVW5pdmVyc2FsTW9kdWxlRGVmaW5pdGlvbihyb290LCBmYWN0b3J5KSB7XG5cdGlmKHR5cGVvZiBleHBvcnRzID09PSAnb2JqZWN0JyAmJiB0eXBlb2YgbW9kdWxlID09PSAnb2JqZWN0Jylcblx0XHRtb2R1bGUuZXhwb3J0cyA9IGZhY3RvcnkoKTtcblx0ZWxzZSBpZih0eXBlb2YgZGVmaW5lID09PSAnZnVuY3Rpb24nICYmIGRlZmluZS5hbWQpXG5cdFx0ZGVmaW5lKFtdLCBmYWN0b3J5KTtcblx0ZWxzZSBpZih0eXBlb2YgZXhwb3J0cyA9PT0gJ29iamVjdCcpXG5cdFx0ZXhwb3J0c1tcIndhc211eFwiXSA9IGZhY3RvcnkoKTtcblx0ZWxzZVxuXHRcdHJvb3RbXCJ3YXNtdXhcIl0gPSBmYWN0b3J5KCk7XG59KShzZWxmLCAoKSA9PiB7XG5yZXR1cm4gIiwiLy8gVGhlIHJlcXVpcmUgc2NvcGVcbnZhciBfX3dlYnBhY2tfcmVxdWlyZV9fID0ge307XG5cbiIsIi8vIGRlZmluZSBnZXR0ZXIgZnVuY3Rpb25zIGZvciBoYXJtb255IGV4cG9ydHNcbl9fd2VicGFja19yZXF1aXJlX18uZCA9IChleHBvcnRzLCBkZWZpbml0aW9uKSA9PiB7XG5cdGZvcih2YXIga2V5IGluIGRlZmluaXRpb24pIHtcblx0XHRpZihfX3dlYnBhY2tfcmVxdWlyZV9fLm8oZGVmaW5pdGlvbiwga2V5KSAmJiAhX193ZWJwYWNrX3JlcXVpcmVfXy5vKGV4cG9ydHMsIGtleSkpIHtcblx0XHRcdE9iamVjdC5kZWZpbmVQcm9wZXJ0eShleHBvcnRzLCBrZXksIHsgZW51bWVyYWJsZTogdHJ1ZSwgZ2V0OiBkZWZpbml0aW9uW2tleV0gfSk7XG5cdFx0fVxuXHR9XG59OyIsIl9fd2VicGFja19yZXF1aXJlX18ubyA9IChvYmosIHByb3ApID0+IChPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwob2JqLCBwcm9wKSkiLCIvLyBkZWZpbmUgX19lc01vZHVsZSBvbiBleHBvcnRzXG5fX3dlYnBhY2tfcmVxdWlyZV9fLnIgPSAoZXhwb3J0cykgPT4ge1xuXHRpZih0eXBlb2YgU3ltYm9sICE9PSAndW5kZWZpbmVkJyAmJiBTeW1ib2wudG9TdHJpbmdUYWcpIHtcblx0XHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgU3ltYm9sLnRvU3RyaW5nVGFnLCB7IHZhbHVlOiAnTW9kdWxlJyB9KTtcblx0fVxuXHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgJ19fZXNNb2R1bGUnLCB7IHZhbHVlOiB0cnVlIH0pO1xufTsiLCIvKlxuICogTUlUIExpY2Vuc2VcbiAqXG4gKiBDb3B5cmlnaHQgKGMpIDIwMjUgIFl1cmlpIFlha3ViaW4gKHl1cmlpLnlha3ViaW5AZ21haWwuY29tKVxuICpcbiAqIFBlcm1pc3Npb24gaXMgZ3JhbnRlZCB0byB1c2UsIGNvcHksIG1vZGlmeSwgYW5kIGRpc3RyaWJ1dGUgdGhpcyBzb2Z0d2FyZVxuICogdW5kZXIgdGhlIE1JVCBMaWNlbnNlLiBTZWUgTElDRU5TRSBmaWxlIGZvciBkZXRhaWxzLlxuICovXG5cbmludGVyZmFjZSBXcmFwcGVySW5zdGFuY2Uge1xuICBzZXQgYmFzZUZzVXJsKHZhbHVlOiBzdHJpbmcpO1xuICBzZXQgb25tZXNzYWdlKGNhbGxiYWNrOiAoKSA9PiB2b2lkKTtcbiAgZ2V0IGRyaXZlcnMoKTogYW55O1xufTtcblxuYXN5bmMgZnVuY3Rpb24gY3JlYXRlSW5zdGFuY2UobW9kdWxlVXJsOiBzdHJpbmcpOiBQcm9taXNlPFdyYXBwZXJJbnN0YW5jZT4ge1xuICBjb25zdCBrcmVzcG9uc2UgPSBhd2FpdCBmZXRjaChtb2R1bGVVcmwpO1xuICBjb25zdCBrYnVmZmVyID0gYXdhaXQga3Jlc3BvbnNlLmFycmF5QnVmZmVyKCk7XG4gIGNvbnN0IGttb2R1bGUgPSBhd2FpdCBXZWJBc3NlbWJseS5jb21waWxlKGtidWZmZXIpO1xuXG4gIGNvbnN0IGxvYWRlckxpc3QgPSBXZWJBc3NlbWJseS5Nb2R1bGUuY3VzdG9tU2VjdGlvbnMoa21vZHVsZSwgXCIuanNkYXRhLmxvYWRlclwiKTtcbiAgY29uc3QgbG9hZGVyQmxvYiA9IG5ldyBCbG9iKGxvYWRlckxpc3QsIHsgdHlwZTogXCJhcHBsaWNhdGlvbi9qYXZhc2NyaXB0XCIgfSk7XG5cbiAgY29uc3QgbG9hZGVyVXJsID0gVVJMLmNyZWF0ZU9iamVjdFVSTChsb2FkZXJCbG9iKTtcbiAgY29uc3QgeyBLZXJuZWwgfSA9IGF3YWl0IGltcG9ydCgvKiB3ZWJwYWNrSWdub3JlOiB0cnVlICovIGxvYWRlclVybCk7XG4gIFVSTC5yZXZva2VPYmplY3RVUkwobG9hZGVyVXJsKTtcblxuICByZXR1cm4gbmV3IEtlcm5lbChrbW9kdWxlKTtcbn1cblxuY29uc3QgZGVmYXVsdENvbnRleHQgPSBPYmplY3QuYXNzaWduKGNyZWF0ZUluc3RhbmNlLCB7XG59KTtcblxuZXhwb3J0IGRlZmF1bHQgZGVmYXVsdENvbnRleHQ7XG4iXSwibmFtZXMiOltdLCJzb3VyY2VSb290IjoiIn0=