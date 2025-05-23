/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

/*
 * Definitions for ALSPS als/ps sensor chip.
 */
#ifndef __ALSPSHUB_H__
#define __ALSPSHUB_H__

#include <linux/ioctl.h>


/*ALSPS related driver tag macro*/
#define ALSPS_SUCCESS						0
#define ALSPS_ERR_I2C						-1
#define ALSPS_ERR_STATUS					-3
#define ALSPS_ERR_SETUP_FAILURE				-4
#define ALSPS_ERR_GETGSENSORDATA			-5
#define ALSPS_ERR_IDENTIFICATION			-6

/*----------------------------------------------------------------------------*/
enum ALSPS_NOTIFY_TYPE {
	ALSPS_NOTIFY_PROXIMITY_CHANGE = 0,
};
/*hs14 code for AL6528A-190 by houxin at 2022/09/28 start*/
/*a06 code for SR-AL7160A-01-150 by zhawei at 20240410 start*/
#if defined(CONFIG_HQ_PROJECT_O22)
enum lcd_id {
	LCD_NONE,
	LCD_FIRST,
	LCD_SECOND,
	LCD_THIRD,
	LCD_FOURTH,
};
#endif
#if defined(CONFIG_HQ_PROJECT_O8)
enum lcd_id {
	LCD_NONE,
	LCD_FIRST,
	LCD_SECOND,
	LCD_THIRD,
	LCD_FOURTH,
	LCD_FIFTH,
	LCD_SIXTH,
};
#endif
#if defined(CONFIG_HQ_PROJECT_O22) || defined(CONFIG_HQ_PROJECT_O8)
struct lcd_id_info
{
	enum lcd_id hwid;
	char *lcd_strdata;
};
#endif
/*a06 code for SR-AL7160A-01-150 by zhawei at 20240410 end*/
/*hs14 code for AL6528A-190 by houxin at 2022/09/28 end*/

#endif

