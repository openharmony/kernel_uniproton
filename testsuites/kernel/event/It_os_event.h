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
 * Description: UniProton 事件测试用例头文件。
 */
#ifndef IT_OS_EVENT_H
#define IT_OS_EVENT_H
#include "osTest.h"

#define SELF_DELETED 0
#define SYS_EXIST_SWTMR 1
#define TEST_HWI_RUNTIME 0x100000
#define TASK_LOOP_NUM 0x100000
#define TASK_NAME_NUM 10
#define IT_TASK_LOOP 20

extern UINT32 g_testTaskID01;
extern UINT32 g_testTaskID02;
extern UINT32 g_testTaskID03;
extern UINT32 g_testTskHandle;

extern VOID ItOsEvent001(VOID);
extern VOID ItOsEvent002(VOID);
extern VOID ItOsEvent003(VOID);
#endif
