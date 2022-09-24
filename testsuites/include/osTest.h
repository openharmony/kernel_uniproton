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
 * Description: UniProton基础测试框架。
 */
#ifndef _OSTEST_H
#define _OSTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iCunit.h"

#include "prt_config.h"

#include "prt_hwi.h"
#include "prt_task.h"
#include "prt_sem.h"
#include "prt_event.h"
#include "prt_mem.h"
#include "prt_queue.h"
#include "prt_tick.h"
#include "prt_timer.h"

#ifdef OS_ARCH_ARMV7_M
#include "os_cpu_armv7_m_external.h"
#endif

#include "securec.h"
#include "securectype.h"

#define VOID void
#define UINT32 U32
#define UINT16 U16

#define PRINTF(fmt, args...) \
    do {                     \
        printf(fmt, ##args); \
    } while (0)

#define OS_KERNEL_CORE_TASK_TEST 1

extern U32 volatile g_testCount;
extern TskHandle g_testTskHandle;
extern TskHandle g_testTaskID01;
extern TskHandle g_testTaskID02;
extern TskHandle g_testTaskID03;
extern TskHandle g_testTaskID04;

extern U32 g_testQueueID01;
extern U32 g_testQueueID02;
extern U32 g_testQueueID03;
extern U32 g_leavingTaskNum;
extern U32 g_testTaskIdArray[OS_TSK_MAX_SUPPORT_NUM + 1];
extern U16 g_index;

extern U32 TEST_TaskCreate(TskHandle *taskPid, struct TskInitParam *initParam);

#define TEST_TSK_MIN_STACK_SIZE OS_TSK_MIN_STACK_SIZE

#ifndef OS_TASK_MIN_TEST_STACK_SIZE
#define OS_TASK_MIN_TEST_STACK_SIZE (OS_TSK_DEFAULT_STACK_SIZE + 0x20)
#endif

#ifndef TASK_TEST
#define TASK_TEST
#endif

#ifndef SWTMR_TEST
#define SWTMR_TEST
#endif

#ifndef QUEUE_TEST
#define QUEUE_TEST
#endif

#ifndef SEM_TEST
#define SEM_TEST
#endif

#ifndef EVENT_TEST
#define EVENT_TEST
#endif

#ifndef HWI_TEST
#define HWI_TEST
#endif

#ifndef TICK_TEST
#define TICK_TEST
#endif

#ifndef EXC_TEST
#define EXC_TEST
#endif

#ifndef MEMCHECK_TEST
#define MEMCHECK_TEST
#endif

#ifndef MACRO_BASE_FUNCTION_TEST
#define MACRO_BASE_FUNCTION_TEST
#endif

#ifndef MACRO_EXC_TEST
#define MACRO_EXC_TEST
#endif

#ifndef MACRO_PRESSURE_TEST
#define MACRO_PRESSURE_TEST
#endif

#ifdef MACRO_PREESSURE_TEST
#define DIVISOR 1
#else
#define DIVISOR 10
#endif

#ifndef TEST_CASE_RES_CHECK
#define TEST_CASE_RES_CHECK
#endif

#ifndef TST_IT
#define TST_IT
#endif

#define TEST_PT 1

#define TEST_BIG 0

#define TASK_PRIO_TEST 25
#define TASK_PRIO_TEST_NORMAL 20

#define TASK_LOOP_NUM 0x100000
#define QUEUE_LOOP_NUM 100
#define HWI_LOOP_NUM 100
#define SWTMR_LOOP_NUM 1000
#define TASK_NAME_NUM 10
#define TEST_TASK_RUNTIME 0x100000
#define TEST_SWTMR_RUNTIME 0x1000000
#define TEST_HWI_RUNTIME 0x100000

#define OS_SYS_MS_PER_SECOND 1000    // Number of ms in one second.
#define OS_SYS_US_PER_SECOND 1000000 // Number of us in one second.

#define OS_MS_PER_TICK (OS_SYS_MS_PER_SECOND / OS_TICK_PER_SECOND)

#define OS_TSK_TEST_STACK_SIZE 0x1000
#define TASK_STACK_SIZE_TEST OS_TSK_TEST_STACK_SIZE
#define TEST_TASK_STACK_SIZE OS_TSK_TEST_STACK_SIZE
#define TASK_CMSIS_STACK_SIZE_TEST 0x600

#define OS_EVENT_TIMEOUT_MAX_VAL 0xFFFFFFFF

extern U32 TaskUsedCountGet(VOID);
#define TASK_EXISTED_NUM TaskUsedCountGet()
#define QUEUE_EXISTED_NUM QueueUsedCountGet()

#define HWI_NUM_INT_NEG (-4)
#define HWI_NUM_INT0 0
#define HWI_NUM_INT1 1
#define HWI_NUM_INT2 2
#define HWI_NUM_INT3 3
#define HWI_NUM_INT4 4
#define HWI_NUM_INT5 5
#define HWI_NUM_INT6 6
#define HWI_NUM_INT7 7
#define HWI_NUM_INT11 11
#define HWI_NUM_INT12 12
#define HWI_NUM_INT13 13
#define HWI_NUM_INT14 14
#define HWI_NUM_INT15 15
#define HWI_NUM_INT16 16
#define HWI_NUM_INT17 17
#define HWI_NUM_INT18 18
#define HWI_NUM_INT21 21
#define HWI_NUM_INT22 22
#define HWI_NUM_INT23 23
#define HWI_NUM_INT24 24
#define HWI_NUM_INT25 25
#define HWI_NUM_INT26 26
#define HWI_NUM_INT27 27
#define HWI_NUM_INT28 28
#define HWI_NUM_INT30 30
#define HWI_NUM_INT31 31
#define HWI_NUM_INT32 32
#define HWI_NUM_INT33 33
#define HWI_NUM_INT45 45
#define HWI_NUM_INT50 50
#define HWI_NUM_INT55 55
#define HWI_NUM_INT60 60
#define HWI_NUM_INT58 58
#define HWI_NUM_INT59 59

#define HWI_NUM_INT75 75
#define HWI_NUM_INT71 71
#define HWI_NUM_INT72 72
#define HWI_NUM_INT73 73

#define HWI_NUM_TEST  HWI_NUM_INT7
#define HWI_NUM_TEST0 HWI_NUM_INT1
#define HWI_NUM_TEST1 HWI_NUM_INT11
#define HWI_NUM_TEST2 HWI_NUM_INT12
#define HWI_NUM_TEST3 HWI_NUM_INT14

#define OSCFG_BASE_IPC_QUEUE_CONFIG OS_QUEUE_MAX_SUPPORT_NUM
#define OSCFG_BASE_IPC_SEM_CONFIG   OS_SEM_MAX_SUPPORT_NUM
#define OSCFG_BASE_CORE_SWTMR_CONFIG OS_TICK_SWITIMER_MAX_NUM
#define OSCFG_BASE_CORE_TSK_CONFIG  OS_TSK_MAX_SUPPORT_NUM
#define dprintf printf

extern TskHandle g_idleTaskId;
extern U32 g_pstEventCb01;
extern U32 g_pstEventCb02;
extern U32 g_pstEventCb03;

extern VOID ItSuiteOsTask(VOID);
extern VOID ItSuiteOsEvent(VOID);
extern VOID ItSuiteOsSem(VOID);

#define OS_MS_TO_TICK(ms) (((ms) * (U64)OS_TICK_PER_SECOND) / 1000)

extern U32 g_auwTestTaskID[OS_TSK_MAX_SUPPORT_NUM + 1];

#endif /* _OSTEST_H */
