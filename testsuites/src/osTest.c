/*
 * Copyright (c) 2022-2022 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

U32 g_passResult = 0;
U32 g_failResult = 0;

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

void TestTaskEntry()
{
    PRINTF("\t\n --- Test Start --- \n\n");
    ICunitInit();

    TestKernel();

    /* The log is used for testing entrance guard, please do not make any changes. */
    PRINTF("\nfailed count:%d, success count:%d\n", g_failResult, g_passResult);
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
