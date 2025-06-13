declare const defaultContext: typeof createInstance;
declare function createInstance(moduleUrl: string): Promise<WrapperInstance>;
export interface WrapperInstance {
	set baseFsUrl(value: string);
	set onmessage(callback: () => void);
	get drivers(): any;
}

export {
	defaultContext as default,
};

export as namespace wasmux;

export {};
