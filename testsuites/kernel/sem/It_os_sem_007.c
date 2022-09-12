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
#include "It_os_sem.h"

static SemHandle g_usSemID;
static VOID TaskF01(void)
{
    UINT32 ret;
    g_testCount++;
    ret = PRT_SemPend(g_usSemID, OS_WAIT_FOREVER);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);
    g_testCount++;
}

static UINT32 Testcase(VOID)
{
    UINT32 ret;
    struct TskInitParam task = { 0 };

    task.taskEntry = (TskEntryFunc)TaskF01;
    task.name = "SemTsk9";
    task.stackSize = TASK_STACK_SIZE_TEST;
    task.taskPrio = TASK_PRIO_TEST - 1;

    g_testCount = 0;

    ret = PRT_SemCreate(0, &g_usSemID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ret = TEST_TaskCreate(&g_testTaskID01, &task);
    ICUNIT_GOTO_EQUAL(ret, OS_OK, ret, EXIT1);

    ICUNIT_GOTO_EQUAL(g_testCount, 1, g_testCount, EXIT2);

EXIT2:
    ret = PRT_TaskDelete(g_testTaskID01);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

EXIT1:
    ret = PRT_SemDelete(g_usSemID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
}

VOID ItOsSem007(void)
{
    TEST_ADD_CASE("ItOsSem007", Testcase, TEST_OS, TEST_SEM, TEST_LEVEL1, TEST_FUNCTION);
}

