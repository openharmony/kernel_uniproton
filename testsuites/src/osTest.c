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
#include "osTest.h"
#include "prt_task.h"
#include "prt_timer.h"
#include "prt_task_external.h"

U32 volatile g_testCount;
TskHandle g_testTskHandle;
TskHandle g_testTaskID01;
TskHandle g_testTaskID02;
TskHandle g_testTaskID03;
TskHandle g_testTaskID04;

U32 TaskUsedCountGet(void)
{
    uintptr_t intSave;
    U32 count = 0;

    intSave = PRT_HwiLock();
    for (U32 index = g_tskBaseId; index < OS_TSK_MAX_SUPPORT_NUM; index++) {
        TskStatus taskStatus = PRT_TaskGetStatus(index);
        if ((taskStatus != OS_INVALID) && (taskStatus & OS_TSK_UNUSED)) {
            count++;
        }
    }
    PRT_HwiRestore(intSave);

    return (OS_TSK_MAX_SUPPORT_NUM - count);
}

U32 TEST_TaskCreate(TskHandle *taskPid, struct TskInitParam *initParam)
{
    U32 ret = PRT_TaskCreate(taskPid, initParam);
    if (ret == OS_OK) {
        return PRT_TaskResume(*taskPid);
    }
    return ret;
}

void TestKernel(void)
{
#if (OS_KERNEL_CORE_TASK_TEST == 1)
    ItSuiteOsTask();
#endif

    ItSuiteOsEvent();

    ItSuiteOsSem();
}

void TestTaskEntry(void)
{
    U32 failResult = 0;
    U32 passResult = 0;
    PRINTF("\t\n --- Test Start --- \n\n");
    ICunitInit();

    TestKernel();

    /* The log is used for testing entrance guard, please do not make any changes. */
    ICunitTestResultGet(&passResult, &failResult);
    PRINTF("\nfailed count:%d, success count:%d\n", failResult, passResult);
    PRINTF("--- Test End ---\n");
}

U32 TestInit(void)
{
    U32 ret;
    struct TskInitParam osTaskInitParam = { 0 };

    osTaskInitParam.taskEntry = (TskEntryFunc)TestTaskEntry;
    osTaskInitParam.stackSize = OS_TSK_TEST_STACK_SIZE;
    osTaskInitParam.name = "IT_TST_INI";
    osTaskInitParam.taskPrio = TASK_PRIO_TEST;

    ret = PRT_TaskCreate(&g_testTskHandle, &osTaskInitParam);
    if (ret != OS_OK) {
        PRINTF("TestInit  error\n");
    }

    ret = PRT_TaskResume(g_testTskHandle);
    if (ret != OS_OK) {
        PRINTF("TestInit  resume error\n");
    }
    return ret;
}
