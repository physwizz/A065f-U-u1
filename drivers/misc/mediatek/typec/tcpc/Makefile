subdir-ccflags-y := -Wall -Werror $(call cc-disable-warning, unused-but-set-variable)
subdir-ccflags-y += -I$(srctree)/drivers/power/supply
obj-$(CONFIG_TCPC_MT6360)		+= tcpc_mt6360.o
obj-$(CONFIG_TCPC_MT6362)		+= tcpc_mt6362.o
obj-$(CONFIG_TCPC_MT6370)		+= tcpc_mt6370.o
obj-$(CONFIG_TCPC_RT1711H)		+= tcpc_rt1711h.o
# hs14 code for SR-AL6528A-01-309|AL6528ADEU-613 by wenyaqi at 2022/10/10 start
obj-$(CONFIG_TCPC_ET7304)		+= tcpc_et7304.o
obj-$(CONFIG_ET_REGMAP)			+= et-regmap.o
# hs14 code for SR-AL6528A-01-309|AL6528ADEU-613 by wenyaqi at 2022/10/10 end
# hs14 code for SR-AL6528A-01-307 by wenyaqi at 2022/08/30 start
obj-$(CONFIG_TCPC_HUSB311)		+= tcpc_husb311.o
obj-$(CONFIG_HUSB_REGMAP)		+= husb-regmap.o
# hs14 code for SR-AL6528A-01-307 by wenyaqi at 2022/08/30 end
# hs14 code for SR-AL6528A-01-308 by wenyaqi at 2022/09/09 start
obj-$(CONFIG_FUSB302_EXT)	+=tcpc_fusb302b/
# hs14 code for SR-AL6528A-01-308 by wenyaqi at 2022/09/09 end

#A06 code for AL7160A-1630 by shixuanxuan at 20240526 start
ifeq ($(CONFIG_TCPC_IF),y)
else
obj-$(CONFIG_TCPC_CLASS)		+= tcpci_core.o tcpci_typec.o tcpci_timer.o \
		tcpm.o tcpci.o pd_dbg_info.o tcpci_alert.o rt_pd_manager.o
endif
#A06 code for AL7160A-1630 by shixuanxuan at 20240526 end

#A06 code for AL7160A-1630 by shixuanxuan at 20240526 start
ifeq ($(CONFIG_TCPC_IF),y)
obj-$(CONFIG_TCPC_IF) += tcpc_if/
else
obj-$(CONFIG_USB_POWER_DELIVERY)	+= tcpci_event.o \
		pd_core.o pd_policy_engine.o pd_process_evt.o \
		pd_dpm_core.o pd_dpm_uvdm.o pd_dpm_alt_mode_dp.o pd_dpm_pdo_select.o\
		pd_dpm_reaction.o \
		pd_process_evt_snk.o pd_process_evt_src.o pd_process_evt_vdm.o \
		pd_process_evt_drs.o pd_process_evt_prs.o pd_process_evt_vcs.o \
		pd_process_evt_dbg.o pd_process_evt_tcp.o pd_process_evt_com.o \
		pd_policy_engine_src.o pd_policy_engine_snk.o pd_policy_engine_ufp.o pd_policy_engine_vcs.o \
		pd_policy_engine_dfp.o pd_policy_engine_dr.o pd_policy_engine_drs.o pd_policy_engine_prs.o \
		pd_policy_engine_dbg.o pd_policy_engine_com.o pd_dpm_alt_mode_dc.o
endif
#A06 code for AL7160A-1630 by shixuanxuan at 20240526 end
# HS03s for SR-AL5625-01-515 by wangzikang at 21210610 start
obj-$(CONFIG_TYPEC_SGM7220) += tcpc_sgm7220.o
obj-$(CONFIG_TCPC_WUSB3801) += tcpc_wusb3801.o
# HS03s for SR-AL5625-01-515 by wangzikang at 21210610 end
#HS03s for SR-AL5625-01-541 by wangzikang at 20210614 start
obj-$(CONFIG_FUSB301A)  += tcpc_fusb301a.o
#HS03s for SR-AL5625-01-541 by wangzikang at 20210614 end
ifeq (y, $(filter y, $(CONFIG_MACH_MT6877) $(CONFIG_MACH_MT6768) $(CONFIG_MACH_MT6781) \
$(CONFIG_MACH_MT6739) $(CONFIG_MACH_MT6833) $(CONFIG_MACH_MT6893) $(CONFIG_MACH_MT6885) \
$(CONFIG_MACH_MT6853) $(CONFIG_MACH_MT6873)))
	ccflags-y += -DADAPT_CHARGER_V1
endif
