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
#include "It_os_task.h"


static VOID TaskF01(VOID)
{
    g_testCount++;

    ICUNIT_ASSERT_EQUAL_VOID(g_testCount, 1, g_testCount);
    PRT_TaskDelete(g_testTaskID01);
}

static UINT32 TestCase(VOID)
{
    UINT32 ret;
    struct TskInitParam task1 = { 0 };
    task1.taskEntry = (TskEntryFunc)TaskF01;
    task1.stackSize = OS_MEM_FSC_PT_SIZE;
    task1.name = "Tsk006A";
    task1.taskPrio = TASK_PRIO_TEST - 1;
    task1.reserved = 0;

    ret = PRT_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_ERRNO_TSK_NO_MEMORY, ret);

    return OS_OK;
}

VOID ItOsTask006(VOID) // IT_Layer_ModuleORFeature_No
{
    TEST_ADD_CASE("ItOsTask006", TestCase, TEST_OS, TEST_TASK, TEST_LEVEL0, TEST_FUNCTION);
}

