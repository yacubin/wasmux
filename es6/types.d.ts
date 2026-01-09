export interface WrapperInstance {
	set baseFsUrl(value: string);
	set onmessage(callback: () => void);
	registerDriver(name: string, driverClass: any): void;
	start(): void;
	stop(): void;
}

export interface WasmuxOptions {
  moduleUrl?: string;
	workerUrl?: string;
}

export default interface IWasmuxDefault {
  (params?: string | WasmuxOptions): Promise<WrapperInstance>;
}
