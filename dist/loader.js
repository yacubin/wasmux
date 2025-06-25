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
//# sourceMappingURL=data:application/json;charset=utf-8;base64,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ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svdW5pdmVyc2FsTW9kdWxlRGVmaW5pdGlvbiIsIndlYnBhY2s6Ly93YXNtdXgvd2VicGFjay9ib290c3RyYXAiLCJ3ZWJwYWNrOi8vd2FzbXV4L3dlYnBhY2svcnVudGltZS9kZWZpbmUgcHJvcGVydHkgZ2V0dGVycyIsIndlYnBhY2s6Ly93YXNtdXgvd2VicGFjay9ydW50aW1lL2hhc093blByb3BlcnR5IHNob3J0aGFuZCIsIndlYnBhY2s6Ly93YXNtdXgvd2VicGFjay9ydW50aW1lL21ha2UgbmFtZXNwYWNlIG9iamVjdCIsIndlYnBhY2s6Ly93YXNtdXgvLi9sb2FkZXIvaW5kZXgudHMiXSwic291cmNlc0NvbnRlbnQiOlsiKGZ1bmN0aW9uIHdlYnBhY2tVbml2ZXJzYWxNb2R1bGVEZWZpbml0aW9uKHJvb3QsIGZhY3RvcnkpIHtcblx0aWYodHlwZW9mIGV4cG9ydHMgPT09ICdvYmplY3QnICYmIHR5cGVvZiBtb2R1bGUgPT09ICdvYmplY3QnKVxuXHRcdG1vZHVsZS5leHBvcnRzID0gZmFjdG9yeSgpO1xuXHRlbHNlIGlmKHR5cGVvZiBkZWZpbmUgPT09ICdmdW5jdGlvbicgJiYgZGVmaW5lLmFtZClcblx0XHRkZWZpbmUoW10sIGZhY3RvcnkpO1xuXHRlbHNlIGlmKHR5cGVvZiBleHBvcnRzID09PSAnb2JqZWN0Jylcblx0XHRleHBvcnRzW1wid2FzbXV4XCJdID0gZmFjdG9yeSgpO1xuXHRlbHNlXG5cdFx0cm9vdFtcIndhc211eFwiXSA9IGZhY3RvcnkoKTtcbn0pKHNlbGYsICgpID0+IHtcbnJldHVybiAiLCIvLyBUaGUgcmVxdWlyZSBzY29wZVxudmFyIF9fd2VicGFja19yZXF1aXJlX18gPSB7fTtcblxuIiwiLy8gZGVmaW5lIGdldHRlciBmdW5jdGlvbnMgZm9yIGhhcm1vbnkgZXhwb3J0c1xuX193ZWJwYWNrX3JlcXVpcmVfXy5kID0gKGV4cG9ydHMsIGRlZmluaXRpb24pID0+IHtcblx0Zm9yKHZhciBrZXkgaW4gZGVmaW5pdGlvbikge1xuXHRcdGlmKF9fd2VicGFja19yZXF1aXJlX18ubyhkZWZpbml0aW9uLCBrZXkpICYmICFfX3dlYnBhY2tfcmVxdWlyZV9fLm8oZXhwb3J0cywga2V5KSkge1xuXHRcdFx0T2JqZWN0LmRlZmluZVByb3BlcnR5KGV4cG9ydHMsIGtleSwgeyBlbnVtZXJhYmxlOiB0cnVlLCBnZXQ6IGRlZmluaXRpb25ba2V5XSB9KTtcblx0XHR9XG5cdH1cbn07IiwiX193ZWJwYWNrX3JlcXVpcmVfXy5vID0gKG9iaiwgcHJvcCkgPT4gKE9iamVjdC5wcm90b3R5cGUuaGFzT3duUHJvcGVydHkuY2FsbChvYmosIHByb3ApKSIsIi8vIGRlZmluZSBfX2VzTW9kdWxlIG9uIGV4cG9ydHNcbl9fd2VicGFja19yZXF1aXJlX18uciA9IChleHBvcnRzKSA9PiB7XG5cdGlmKHR5cGVvZiBTeW1ib2wgIT09ICd1bmRlZmluZWQnICYmIFN5bWJvbC50b1N0cmluZ1RhZykge1xuXHRcdE9iamVjdC5kZWZpbmVQcm9wZXJ0eShleHBvcnRzLCBTeW1ib2wudG9TdHJpbmdUYWcsIHsgdmFsdWU6ICdNb2R1bGUnIH0pO1xuXHR9XG5cdE9iamVjdC5kZWZpbmVQcm9wZXJ0eShleHBvcnRzLCAnX19lc01vZHVsZScsIHsgdmFsdWU6IHRydWUgfSk7XG59OyIsIi8qXG4gKiBNSVQgTGljZW5zZVxuICpcbiAqIENvcHlyaWdodCAoYykgMjAyNSAgWXVyaWkgWWFrdWJpbiAoeXVyaWkueWFrdWJpbkBnbWFpbC5jb20pXG4gKlxuICogUGVybWlzc2lvbiBpcyBncmFudGVkIHRvIHVzZSwgY29weSwgbW9kaWZ5LCBhbmQgZGlzdHJpYnV0ZSB0aGlzIHNvZnR3YXJlXG4gKiB1bmRlciB0aGUgTUlUIExpY2Vuc2UuIFNlZSBMSUNFTlNFIGZpbGUgZm9yIGRldGFpbHMuXG4gKi9cblxuaW50ZXJmYWNlIFdyYXBwZXJJbnN0YW5jZSB7XG4gIHNldCBiYXNlRnNVcmwodmFsdWU6IHN0cmluZyk7XG4gIHNldCBvbm1lc3NhZ2UoY2FsbGJhY2s6ICgpID0+IHZvaWQpO1xuICByZWdpc3RlckRyaXZlcihuYW1lOiBzdHJpbmcsIGRyaXZlckNsYXNzOiBhbnkpOiB2b2lkO1xuICBzdGFydCgpOiB2b2lkO1xuICBzdG9wKCk6IHZvaWQ7XG59O1xuXG5jbGFzcyBVc2VySW5zdGFuY2UgaW1wbGVtZW50cyBXcmFwcGVySW5zdGFuY2Uge1xuICBwcml2YXRlIF9jb250ZXh0OiBhbnk7XG4gIHByaXZhdGUgX2xvYWRlclVybDogc3RyaW5nO1xuICBwcml2YXRlIF93b3JrZXJVcmw6IHN0cmluZztcblxuICBjb25zdHJ1Y3Rvcihjb250ZXh0OiBhbnksIGxvYWRlclVybDogc3RyaW5nLCB3b3JrZXJVcmw6IHN0cmluZykge1xuICAgIHRoaXMuX2NvbnRleHQgPSBjb250ZXh0O1xuICAgIHRoaXMuX2xvYWRlclVybCA9IGxvYWRlclVybDtcbiAgICB0aGlzLl93b3JrZXJVcmwgPSB3b3JrZXJVcmw7XG4gIH1cblxuICBwdWJsaWMgc2V0IGJhc2VGc1VybCh2YWx1ZTogc3RyaW5nKSB7XG4gIH1cblxuICBwdWJsaWMgc2V0IG9ubWVzc2FnZShjYWxsYmFjazogKCkgPT4gdm9pZCkge1xuICB9XG5cbiAgcHVibGljIHJlZ2lzdGVyRHJpdmVyKG5hbWU6IHN0cmluZywgZHJpdmVyQ2xhc3M6IGFueSk6IHZvaWQge1xuICB9XG5cbiAgcHVibGljIHN0YXJ0KCk6IHZvaWQge1xuICAgIHNldFRpbWVvdXQoKCkgPT4gdGhpcy5fY29udGV4dC5pbml0KCksIDApO1xuICB9XG5cbiAgcHVibGljIHN0b3AoKTogdm9pZCB7XG4gICAgVVJMLnJldm9rZU9iamVjdFVSTCh0aGlzLl9sb2FkZXJVcmwpO1xuICAgIFVSTC5yZXZva2VPYmplY3RVUkwodGhpcy5fd29ya2VyVXJsKTtcbiAgfVxufTtcblxuYXN5bmMgZnVuY3Rpb24gY3JlYXRlSW5zdGFuY2UobW9kdWxlVXJsOiBzdHJpbmcpOiBQcm9taXNlPFdyYXBwZXJJbnN0YW5jZT4ge1xuICBjb25zdCBrcmVzcG9uc2UgPSBhd2FpdCBmZXRjaChtb2R1bGVVcmwpO1xuICBjb25zdCBrYnVmZmVyID0gYXdhaXQga3Jlc3BvbnNlLmFycmF5QnVmZmVyKCk7XG4gIGNvbnN0IG1vZHVsZSA9IGF3YWl0IFdlYkFzc2VtYmx5LmNvbXBpbGUoa2J1ZmZlcik7XG5cbiAgY29uc3QgbG9hZGVyTGlzdCA9IFdlYkFzc2VtYmx5Lk1vZHVsZS5jdXN0b21TZWN0aW9ucyhtb2R1bGUsIFwiLmpzZGF0YS5sb2FkZXJcIik7XG4gIGNvbnN0IGxvYWRlckJsb2IgPSBuZXcgQmxvYihsb2FkZXJMaXN0LCB7IHR5cGU6IFwiYXBwbGljYXRpb24vamF2YXNjcmlwdFwiIH0pO1xuICBjb25zdCBsb2FkZXJVcmwgPSBVUkwuY3JlYXRlT2JqZWN0VVJMKGxvYWRlckJsb2IpO1xuXG4gIGNvbnN0IHdvcmtlckxpc3QgPSBXZWJBc3NlbWJseS5Nb2R1bGUuY3VzdG9tU2VjdGlvbnMobW9kdWxlLCBcIi5qc2RhdGEud29ya2VyXCIpO1xuICBjb25zdCB3b3JrZXJCbG9iID0gbmV3IEJsb2Iod29ya2VyTGlzdCwgeyB0eXBlOiAnYXBwbGljYXRpb24vamF2YXNjcmlwdCcgfSk7XG4gIGNvbnN0IHdvcmtlclVybCA9IFVSTC5jcmVhdGVPYmplY3RVUkwod29ya2VyQmxvYik7XG5cbiAgY29uc3QgeyBNYWluQ29udGV4dCB9ID0gYXdhaXQgaW1wb3J0KC8qIHdlYnBhY2tJZ25vcmU6IHRydWUgKi8gbG9hZGVyVXJsKTtcblxuICBjb25zdCBtYWluQ29udGV4dCA9IE1haW5Db250ZXh0LmNyZWF0ZShtb2R1bGUsIHdvcmtlclVybCk7XG4gIHJldHVybiBuZXcgVXNlckluc3RhbmNlKG1haW5Db250ZXh0LCBsb2FkZXJVcmwsIHdvcmtlclVybCk7XG59XG5cbmNvbnN0IGRlZmF1bHRDb250ZXh0ID0gT2JqZWN0LmFzc2lnbihjcmVhdGVJbnN0YW5jZSwge1xufSk7XG5cbmV4cG9ydCBkZWZhdWx0IGRlZmF1bHRDb250ZXh0O1xuIl0sIm5hbWVzIjpbXSwic291cmNlUm9vdCI6IiJ9