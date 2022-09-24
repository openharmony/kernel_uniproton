/*
 * Copyright (c) 2022-2022 Huawei Technologies Co., Ltd. All rights reserved.
 *
 * UniProton is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Create: 2022-09-21
 * Description: UniProton 任务测试用例头文件。
 */
#ifndef IT_OS_TASK_H
#define IT_OS_TASK_H
#include "osTest.h"

#define SELF_DELETED 0
#define SYS_EXIST_SWTMR 1

#define TEST_HWI_RUNTIME 0x100000
#define TASK_LOOP_NUM 0x100000

#define TASK_NAME_NUM 10
#define IT_TASK_LOOP 20

extern U32 g_stEventCB;
extern U32 g_stEventCB1;
extern U32 g_stEventCB2;
extern U32 g_stEventCB3;

extern VOID ItOsTask001(VOID);
extern VOID ItOsTask002(VOID);
extern VOID ItOsTask003(VOID);
extern VOID ItOsTask004(VOID);
extern VOID ItOsTask005(VOID);
extern VOID ItOsTask006(VOID);
extern VOID ItOsTask007(VOID);
extern VOID ItOsTask008(VOID);
extern VOID ItOsTask010(VOID);
extern VOID ItOsTask011(VOID);
extern VOID ItOsTask012(VOID);
extern VOID ItOsTask013(VOID);
extern VOID ItOsTask014(VOID);
extern VOID ItOsTask015(VOID);
extern VOID ItOsTask016(VOID);
extern VOID ItOsTask017(VOID);
extern VOID ItOsTask018(VOID);
extern VOID ItOsTask019(VOID);
extern VOID ItOsTask020(VOID);
extern VOID ItOsTask021(VOID);
extern VOID ItOsTask022(VOID);
extern VOID ItOsTask023(VOID);
extern VOID ItOsTask024(VOID);
extern VOID ItOsTask025(VOID);
extern VOID ItOsTask026(VOID);
extern VOID ItOsTask027(VOID);
extern VOID ItOsTask028(VOID);
extern VOID ItOsTask029(VOID);
extern VOID ItOsTask030(VOID);
extern VOID ItOsTask031(VOID);
extern VOID ItOsTask032(VOID);
extern VOID ItOsTask033(VOID);
extern VOID ItOsTask034(VOID);
extern VOID ItOsTask035(VOID);
extern VOID ItOsTask036(VOID);
extern VOID ItOsTask037(VOID);
extern VOID ItOsTask038(VOID);

#endif
