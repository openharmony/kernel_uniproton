/*
 * Copyright (c) 2013-2019 Huawei Technologies Co., Ltd. All rights reserved.
 * Copyright (c) 2020-2021 Huawei Device Co., Ltd. All rights reserved.
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
    UINT32 ret;
    g_testCount++;

    ret = PRT_TaskDelete(g_testTaskID01);
    ICUNIT_ASSERT_EQUAL_VOID(ret, OS_OK, ret);
    return;
}

static UINT32 TestCase(VOID)
{
    UINT32 ret;
    struct TskInitParam task1 = { 0 };
    task1.taskEntry = (TskEntryFunc)TaskF01;
    task1.stackSize = TASK_STACK_SIZE_TEST;
    task1.name = "Tsk011A!@#$%^&*_+~<>";
    task1.taskPrio = TASK_PRIO_TEST - 1;

    g_testCount = 0;

    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);
    ICUNIT_GOTO_EQUAL(g_testCount, 1, g_testCount, EXIT);

    return OS_OK;

EXIT:
    ret = PRT_TaskDelete(g_testTaskID01);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
}

VOID ItOsTask011(VOID) // IT_Layer_ModuleORFeature_No
{
    TEST_ADD_CASE("ItOsTask011", TestCase, TEST_OS, TEST_TASK, TEST_LEVEL0, TEST_FUNCTION);
}

