// SPDX-License-Identifier: GPL-2.0+
/*
 * Copied from wol.c command file.
 *
 * Copyright 2023 VCTLabs.com
 * (C) Copyright 2018
 * Lothar Felte, lothar.felten@gmail.com
 */

/*
 * SWUpdate trigger packet support
 */
#include <common.h>
#include <command.h>
#include <net.h>

#if defined(CONFIG_CMD_SWU)
void swu_set_timeout(ulong);

int do_swu(struct cmd_tbl *cmdtp, int flag, int argc, char * const argv[])
{
	/* Validate arguments */
	if (argc < 2)
		return CMD_RET_USAGE;
	swu_set_timeout(simple_strtol(argv[1], NULL, 10) * 1000);
	if (net_loop(SWU) < 0)
		return CMD_RET_FAILURE;
	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
	swu,	2,	1,	do_swu,
	"wait for an incoming swupdate trigger packet",
	"Timeout (sec)"
);
#endif
