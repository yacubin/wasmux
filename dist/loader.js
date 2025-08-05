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
class UserInstance {
    _context;
    _loaderUrl;
    _workerUrl;
    constructor(context, loaderUrl, workerUrl) {
        this._context = context;
        this._loaderUrl = loaderUrl;
        this._workerUrl = workerUrl;
    }
    set baseFsUrl(value) {
    }
    set onmessage(callback) {
    }
    registerDriver(name, driverClass) {
    }
    start() {
        setTimeout(() => this._context.init(), 0);
    }
    stop() {
        URL.revokeObjectURL(this._loaderUrl);
        URL.revokeObjectURL(this._workerUrl);
    }
}
;
async function createInstance(moduleUrl) {
    const kresponse = await fetch(moduleUrl);
    const kbuffer = await kresponse.arrayBuffer();
    const module = await WebAssembly.compile(kbuffer);
    const loaderList = WebAssembly.Module.customSections(module, ".jsdata.loader");
    const loaderBlob = new Blob(loaderList, { type: "application/javascript" });
    const loaderUrl = URL.createObjectURL(loaderBlob);
    const workerList = WebAssembly.Module.customSections(module, ".jsdata.worker");
    const workerBlob = new Blob(workerList, { type: 'application/javascript' });
    const workerUrl = URL.createObjectURL(workerBlob);
    const { MainContext } = await import(/* webpackIgnore: true */ loaderUrl);
    const mainContext = MainContext.create(module, workerUrl);
    return new UserInstance(mainContext, loaderUrl, workerUrl);
}
const defaultContext = Object.assign(createInstance, {});
/* harmony default export */ const __WEBPACK_DEFAULT_EXPORT__ = (defaultContext);

__webpack_exports__ = __webpack_exports__["default"];
/******/ 	return __webpack_exports__;
/******/ })()
;
});
//# sourceMappingURL=data:application/json;charset=utf-8;base64,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ZXMiOlsid2VicGFjazovL3dhc211eC93ZWJwYWNrL3VuaXZlcnNhbE1vZHVsZURlZmluaXRpb24iLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svYm9vdHN0cmFwIiwid2VicGFjazovL3dhc211eC93ZWJwYWNrL3J1bnRpbWUvZGVmaW5lIHByb3BlcnR5IGdldHRlcnMiLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svcnVudGltZS9oYXNPd25Qcm9wZXJ0eSBzaG9ydGhhbmQiLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svcnVudGltZS9tYWtlIG5hbWVzcGFjZSBvYmplY3QiLCJ3ZWJwYWNrOi8vd2FzbXV4Ly4vbG9hZGVyL2luZGV4LnRzIl0sInNvdXJjZXNDb250ZW50IjpbIihmdW5jdGlvbiB3ZWJwYWNrVW5pdmVyc2FsTW9kdWxlRGVmaW5pdGlvbihyb290LCBmYWN0b3J5KSB7XG5cdGlmKHR5cGVvZiBleHBvcnRzID09PSAnb2JqZWN0JyAmJiB0eXBlb2YgbW9kdWxlID09PSAnb2JqZWN0Jylcblx0XHRtb2R1bGUuZXhwb3J0cyA9IGZhY3RvcnkoKTtcblx0ZWxzZSBpZih0eXBlb2YgZGVmaW5lID09PSAnZnVuY3Rpb24nICYmIGRlZmluZS5hbWQpXG5cdFx0ZGVmaW5lKFtdLCBmYWN0b3J5KTtcblx0ZWxzZSBpZih0eXBlb2YgZXhwb3J0cyA9PT0gJ29iamVjdCcpXG5cdFx0ZXhwb3J0c1tcIndhc211eFwiXSA9IGZhY3RvcnkoKTtcblx0ZWxzZVxuXHRcdHJvb3RbXCJ3YXNtdXhcIl0gPSBmYWN0b3J5KCk7XG59KShzZWxmLCAoKSA9PiB7XG5yZXR1cm4gIiwiLy8gVGhlIHJlcXVpcmUgc2NvcGVcbnZhciBfX3dlYnBhY2tfcmVxdWlyZV9fID0ge307XG5cbiIsIi8vIGRlZmluZSBnZXR0ZXIgZnVuY3Rpb25zIGZvciBoYXJtb255IGV4cG9ydHNcbl9fd2VicGFja19yZXF1aXJlX18uZCA9IChleHBvcnRzLCBkZWZpbml0aW9uKSA9PiB7XG5cdGZvcih2YXIga2V5IGluIGRlZmluaXRpb24pIHtcblx0XHRpZihfX3dlYnBhY2tfcmVxdWlyZV9fLm8oZGVmaW5pdGlvbiwga2V5KSAmJiAhX193ZWJwYWNrX3JlcXVpcmVfXy5vKGV4cG9ydHMsIGtleSkpIHtcblx0XHRcdE9iamVjdC5kZWZpbmVQcm9wZXJ0eShleHBvcnRzLCBrZXksIHsgZW51bWVyYWJsZTogdHJ1ZSwgZ2V0OiBkZWZpbml0aW9uW2tleV0gfSk7XG5cdFx0fVxuXHR9XG59OyIsIl9fd2VicGFja19yZXF1aXJlX18ubyA9IChvYmosIHByb3ApID0+IChPYmplY3QucHJvdG90eXBlLmhhc093blByb3BlcnR5LmNhbGwob2JqLCBwcm9wKSkiLCIvLyBkZWZpbmUgX19lc01vZHVsZSBvbiBleHBvcnRzXG5fX3dlYnBhY2tfcmVxdWlyZV9fLnIgPSAoZXhwb3J0cykgPT4ge1xuXHRpZih0eXBlb2YgU3ltYm9sICE9PSAndW5kZWZpbmVkJyAmJiBTeW1ib2wudG9TdHJpbmdUYWcpIHtcblx0XHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgU3ltYm9sLnRvU3RyaW5nVGFnLCB7IHZhbHVlOiAnTW9kdWxlJyB9KTtcblx0fVxuXHRPYmplY3QuZGVmaW5lUHJvcGVydHkoZXhwb3J0cywgJ19fZXNNb2R1bGUnLCB7IHZhbHVlOiB0cnVlIH0pO1xufTsiLCIvKlxuICogTUlUIExpY2Vuc2VcbiAqXG4gKiBDb3B5cmlnaHQgKGMpIDIwMjUgIFl1cmlpIFlha3ViaW4gKHl1cmlpLnlha3ViaW5AZ21haWwuY29tKVxuICpcbiAqIFBlcm1pc3Npb24gaXMgZ3JhbnRlZCB0byB1c2UsIGNvcHksIG1vZGlmeSwgYW5kIGRpc3RyaWJ1dGUgdGhpcyBzb2Z0d2FyZVxuICogdW5kZXIgdGhlIE1JVCBMaWNlbnNlLiBTZWUgTElDRU5TRSBmaWxlIGZvciBkZXRhaWxzLlxuICovXG5cbmludGVyZmFjZSBXcmFwcGVySW5zdGFuY2Uge1xuICBzZXQgYmFzZUZzVXJsKHZhbHVlOiBzdHJpbmcpO1xuICBzZXQgb25tZXNzYWdlKGNhbGxiYWNrOiAoKSA9PiB2b2lkKTtcbiAgcmVnaXN0ZXJEcml2ZXIobmFtZTogc3RyaW5nLCBkcml2ZXJDbGFzczogYW55KTogdm9pZDtcbiAgc3RhcnQoKTogdm9pZDtcbiAgc3RvcCgpOiB2b2lkO1xufTtcblxuY2xhc3MgVXNlckluc3RhbmNlIGltcGxlbWVudHMgV3JhcHBlckluc3RhbmNlIHtcbiAgcHJpdmF0ZSBfY29udGV4dDogYW55O1xuICBwcml2YXRlIF9sb2FkZXJVcmw6IHN0cmluZztcbiAgcHJpdmF0ZSBfd29ya2VyVXJsOiBzdHJpbmc7XG5cbiAgY29uc3RydWN0b3IoY29udGV4dDogYW55LCBsb2FkZXJVcmw6IHN0cmluZywgd29ya2VyVXJsOiBzdHJpbmcpIHtcbiAgICB0aGlzLl9jb250ZXh0ID0gY29udGV4dDtcbiAgICB0aGlzLl9sb2FkZXJVcmwgPSBsb2FkZXJVcmw7XG4gICAgdGhpcy5fd29ya2VyVXJsID0gd29ya2VyVXJsO1xuICB9XG5cbiAgcHVibGljIHNldCBiYXNlRnNVcmwodmFsdWU6IHN0cmluZykge1xuICB9XG5cbiAgcHVibGljIHNldCBvbm1lc3NhZ2UoY2FsbGJhY2s6ICgpID0+IHZvaWQpIHtcbiAgfVxuXG4gIHB1YmxpYyByZWdpc3RlckRyaXZlcihuYW1lOiBzdHJpbmcsIGRyaXZlckNsYXNzOiBhbnkpOiB2b2lkIHtcbiAgfVxuXG4gIHB1YmxpYyBzdGFydCgpOiB2b2lkIHtcbiAgICBzZXRUaW1lb3V0KCgpID0+IHRoaXMuX2NvbnRleHQuaW5pdCgpLCAwKTtcbiAgfVxuXG4gIHB1YmxpYyBzdG9wKCk6IHZvaWQge1xuICAgIFVSTC5yZXZva2VPYmplY3RVUkwodGhpcy5fbG9hZGVyVXJsKTtcbiAgICBVUkwucmV2b2tlT2JqZWN0VVJMKHRoaXMuX3dvcmtlclVybCk7XG4gIH1cbn07XG5cbmFzeW5jIGZ1bmN0aW9uIGNyZWF0ZUluc3RhbmNlKG1vZHVsZVVybDogc3RyaW5nKTogUHJvbWlzZTxXcmFwcGVySW5zdGFuY2U+IHtcbiAgY29uc3Qga3Jlc3BvbnNlID0gYXdhaXQgZmV0Y2gobW9kdWxlVXJsKTtcbiAgY29uc3Qga2J1ZmZlciA9IGF3YWl0IGtyZXNwb25zZS5hcnJheUJ1ZmZlcigpO1xuICBjb25zdCBtb2R1bGUgPSBhd2FpdCBXZWJBc3NlbWJseS5jb21waWxlKGtidWZmZXIpO1xuXG4gIGNvbnN0IGxvYWRlckxpc3QgPSBXZWJBc3NlbWJseS5Nb2R1bGUuY3VzdG9tU2VjdGlvbnMobW9kdWxlLCBcIi5qc2RhdGEubG9hZGVyXCIpO1xuICBjb25zdCBsb2FkZXJCbG9iID0gbmV3IEJsb2IobG9hZGVyTGlzdCwgeyB0eXBlOiBcImFwcGxpY2F0aW9uL2phdmFzY3JpcHRcIiB9KTtcbiAgY29uc3QgbG9hZGVyVXJsID0gVVJMLmNyZWF0ZU9iamVjdFVSTChsb2FkZXJCbG9iKTtcblxuICBjb25zdCB3b3JrZXJMaXN0ID0gV2ViQXNzZW1ibHkuTW9kdWxlLmN1c3RvbVNlY3Rpb25zKG1vZHVsZSwgXCIuanNkYXRhLndvcmtlclwiKTtcbiAgY29uc3Qgd29ya2VyQmxvYiA9IG5ldyBCbG9iKHdvcmtlckxpc3QsIHsgdHlwZTogJ2FwcGxpY2F0aW9uL2phdmFzY3JpcHQnIH0pO1xuICBjb25zdCB3b3JrZXJVcmwgPSBVUkwuY3JlYXRlT2JqZWN0VVJMKHdvcmtlckJsb2IpO1xuXG4gIGNvbnN0IHsgTWFpbkNvbnRleHQgfSA9IGF3YWl0IGltcG9ydCgvKiB3ZWJwYWNrSWdub3JlOiB0cnVlICovIGxvYWRlclVybCk7XG5cbiAgY29uc3QgbWFpbkNvbnRleHQgPSBNYWluQ29udGV4dC5jcmVhdGUobW9kdWxlLCB3b3JrZXJVcmwpO1xuICByZXR1cm4gbmV3IFVzZXJJbnN0YW5jZShtYWluQ29udGV4dCwgbG9hZGVyVXJsLCB3b3JrZXJVcmwpO1xufVxuXG5jb25zdCBkZWZhdWx0Q29udGV4dCA9IE9iamVjdC5hc3NpZ24oY3JlYXRlSW5zdGFuY2UsIHtcbn0pO1xuXG5leHBvcnQgZGVmYXVsdCBkZWZhdWx0Q29udGV4dDtcbiJdLCJuYW1lcyI6W10sInNvdXJjZVJvb3QiOiIifQ==