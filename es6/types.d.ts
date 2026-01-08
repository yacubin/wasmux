export interface WrapperInstance {
	set baseFsUrl(value: string);
	set onmessage(callback: () => void);
	registerDriver(name: string, driverClass: any): void;
	start(): void;
	stop(): void;
};

export default interface IWasmuxDefault {
  (params?: string | Buffer): Promise<WrapperInstance>;
};
