/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _WASMUX_REBOOT_H
#define _WASMUX_REBOOT_H

#define	LINUX_REBOOT_MAGIC1	0xfee1dead
#define	LINUX_REBOOT_MAGIC2	672274793

#define LINUX_REBOOT_CMD_RESTART      0x01234567
#define LINUX_REBOOT_CMD_HALT         0xcdef0123
#define LINUX_REBOOT_CMD_CAD_ON       0x89abcdef
#define LINUX_REBOOT_CMD_CAD_OFF      0x00000000
#define LINUX_REBOOT_CMD_POWER_OFF    0x4321fedc
#define LINUX_REBOOT_CMD_RESTART2     0xa1b2c3d4
#define LINUX_REBOOT_CMD_SW_SUSPEND   0xd000fce2
#define LINUX_REBOOT_CMD_KEXEC        0x45584543

#endif /* _WASMUX_REBOOT_H */
