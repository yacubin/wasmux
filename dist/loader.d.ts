declare const defaultContext: typeof createInstance;
declare function createInstance(moduleUrl: string): Promise<WrapperInstance>;
export interface WrapperInstance {
	set baseFsUrl(value: string);
	set onmessage(callback: () => void);
	registerDriver(name: string, driverClass: any): void;
	start(): void;
	stop(): void;
}

export {
	defaultContext as default,
};

export as namespace wasmux;

export {};
