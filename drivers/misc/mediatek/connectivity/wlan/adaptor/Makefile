###############################################################################
# Necessary Check

ifndef TOP
    TOP := $(srctree)/..
endif

# Force build fail on modpost warning
KBUILD_MODPOST_FAIL_ON_WARNINGS := y

ccflags-y += \
    -I$(srctree)/drivers/misc/mediatek/include/mt-plat \
    -I$(TOP)/common/common_main/include \
    -I$(TOP)/common/common_main/linux/include

ifeq ($(CONNAC_VER), 2_0)
ccflags-y += -I$(TOP)/conninfra/include
ccflags-y += -I$(TOP)/conninfra/debug_utility
ccflags-y += -I$(TOP)/conninfra/debug_utility/include
ccflags-y += -I$(TOP)/conninfra/debug_utility/connsyslog
ccflags-y += -I$(TOP)/conninfra/debug_utility/coredump
endif

ifeq ($(CONFIG_MTK_CONN_LTE_IDC_SUPPORT),y)
    ccflags-y += -DWMT_IDC_SUPPORT=1
else
    ccflags-y += -DWMT_IDC_SUPPORT=0
endif

ifeq ($(CONNAC_VER), 2_0)
ccflags-y += -DCFG_ANDORID_CONNINFRA_SUPPORT=1
ccflags-y += -DCFG_ANDORID_CONNINFRA_COREDUMP_SUPPORT=1
else
ccflags-y += -DCFG_ANDORID_CONNINFRA_SUPPORT=0
ccflags-y += -DCFG_ANDORID_CONNINFRA_COREDUMP_SUPPORT=0
endif

ifeq ($(CONFIG_MTK_TC10_FEATURE), y)
    ccflags-y += -DCFG_TC10_FEATURE=1
else
    ccflags-y += -DCFG_TC10_FEATURE=0
endif

ccflags-y += -D MTK_WCN_WMT_STP_EXP_SYMBOL_ABSTRACT

ccflags-y += -D CREATE_NODE_DYNAMIC=1

MODULE_NAME := wmt_chrdev_wifi
obj-y += $(MODULE_NAME).o

# Wi-Fi character device driver
$(MODULE_NAME)-objs += wmt_cdev_wifi.o
ifeq ($(CONNAC_VER), 2_0)
$(MODULE_NAME)-objs += wifi_pwr_on.o
endif
