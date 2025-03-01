/*
 *
 *  Copyright (C) 2025  Yurii Yakubin (yurii.yakubin@gmail.com)
 *
 */

#ifndef _SYS_REBOOT_H
#define _SYS_REBOOT_H

#include <wasmux/reboot.h>

#ifdef __cplusplus
extern "C" {
#endif

#define RB_AUTOBOOT     LINUX_REBOOT_CMD_RESTART
#define RB_HALT_SYSTEM  LINUX_REBOOT_CMD_HALT
#define RB_ENABLE_CAD   LINUX_REBOOT_CMD_CAD_ON
#define RB_DISABLE_CAD  LINUX_REBOOT_CMD_CAD_OFF
#define RB_POWER_OFF    LINUX_REBOOT_CMD_POWER_OFF
#define RB_SW_SUSPEND   LINUX_REBOOT_CMD_SW_SUSPEND
#define RB_KEXEC        LINUX_REBOOT_CMD_KEXEC

int reboot(int type);

#ifdef __cplusplus
}
#endif

#endif /* _SYS_REBOOT_H */
