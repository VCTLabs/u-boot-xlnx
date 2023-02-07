/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * sw - SoftWareUpdate
 *
 * Simple ethernet trigger packet with custom ether type
 * - EtherType 0xB990 packets
 *
 * Copyright 2023 VCTLabs.com
 */

#if defined(CONFIG_CMD_SWU)

#ifndef __SWU_H__
#define __SWU_H__

#include <net.h>

/**********************************************************************/

#define SWU_DEFAULT_TIMEOUT             5000

/*
 * Initialize swu (beginning of netloop)
 */
void swu_start(void);

/*
 * Set the timeout for the reception of a swupdate trigger packet
 *
 * @param timeout in milliseconds
 */
void swu_set_timeout(ulong timeout);

/**********************************************************************/

#endif /* __SWU_H__ */
#endif
