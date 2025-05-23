/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef __LINUX_TCPCI_TYPEC_H
#define __LINUX_TCPCI_TYPEC_H
#include "tcpci.h"

struct tcpc_device;
extern bool tcpc_typec_is_act_as_sink_role(struct tcpc_device *tcpc);

/******************************************************************************
 *  Call following function to trigger TYPEC Connection State Change
 *
 * 1. H/W -> CC/PS Change.
 * 2. Timer -> CCDebounce or PDDebounce or others Timeout
 * 3. Policy Engine -> PR_SWAP, Error_Recovery, PE_Idle
 *****************************************************************************/

extern int tcpc_typec_enter_lpm_again(struct tcpc_device *tcpc);
extern int tcpc_typec_handle_cc_change(struct tcpc_device *tcpc);

extern int tcpc_typec_handle_ps_change(
		struct tcpc_device *tcpc, int vbus_level);

extern int tcpc_typec_handle_timeout(
		struct tcpc_device *tcpc, uint32_t timer_id);

extern int tcpc_typec_handle_vsafe0v(struct tcpc_device *tcpc);

extern int tcpc_typec_set_rp_level(struct tcpc_device *tcpc, uint8_t rp_lvl);

extern int tcpc_typec_error_recovery(struct tcpc_device *tcpc);

extern int tcpc_typec_disable(struct tcpc_device *tcpc);
extern int tcpc_typec_enable(struct tcpc_device *tcpc);

extern int tcpc_typec_change_role(
	struct tcpc_device *tcpc, uint8_t typec_role, bool postpone);

#ifdef CONFIG_USB_POWER_DELIVERY
extern int tcpc_typec_handle_pe_pr_swap(struct tcpc_device *tcpc);
#endif /* CONFIG_USB_POWER_DELIVERY */

#ifdef CONFIG_TYPEC_CAP_ROLE_SWAP
extern int tcpc_typec_swap_role(struct tcpc_device *tcpc);
#endif /* CONFIG_TYPEC_CAP_ROLE_SWAP */

#ifdef CONFIG_WATER_DETECTION
extern int tcpc_typec_handle_wd(struct tcpc_device *tcpc, bool wd);
#endif /* CONFIG_WATER_DETECTION */

#ifdef CONFIG_CABLE_TYPE_DETECTION
extern int tcpc_typec_handle_ctd(struct tcpc_device *tcpc,
				 enum tcpc_cable_type cable_type);
#endif /* CONFIG_CABLE_TYPEC_DETECTION */
/* A06 code for P240528-06609 by shixuanxuan at 20240531 start*/
#ifdef CONFIG_HQ_PROJECT_O8
extern bool g_pd_online;
EXPORT_SYMBOL(g_pd_online);
#endif
/* A06 code for P240528-06609 by shixuanxuan at 20240531 end*/

#define typec_get_cc1()		\
	tcpc->typec_remote_cc[0]
#define typec_get_cc2()		\
	tcpc->typec_remote_cc[1]
#define typec_get_cc_res()	\
	(tcpc->typec_polarity ? typec_get_cc2() : typec_get_cc1())

#endif /* #ifndef __LINUX_TCPCI_TYPEC_H */
