// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2023 VCTLabs.com
 */

#include <common.h>
#include <command.h>
#include <env.h>
#include <net.h>
#include "swu.h"

static ulong swu_timeout = SWU_DEFAULT_TIMEOUT;

void swu_set_timeout(ulong timeout)
{
	swu_timeout = timeout;
}

static void swu_timeout_handler(void)
{
	eth_halt();
	net_set_state(NETLOOP_FAIL);
}

void swu_start(void)
{
	net_set_timeout_handler(swu_timeout, swu_timeout_handler);
	net_set_udp_handler(NULL);
}
