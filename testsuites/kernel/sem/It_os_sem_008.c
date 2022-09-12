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

static SemHandle g_semID;
static VOID TaskF01(VOID)
{
    UINT32 ret = PRT_SemPend(g_semID, OS_WAIT_FOREVER);
    ICUNIT_ASSERT_EQUAL(ret, 0, ret);
    return;
}

static UINT32 Testcase(VOID)
{
    UINT32 ret;
    struct TskInitParam task = { 0 };

    ret = PRT_SemCreate(1, &g_semID); // 1, The semaphore count, number of available semaphores.
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    task.taskEntry = (TskEntryFunc)TaskF01;
    task.name = "Sem12";
    task.stackSize = TASK_STACK_SIZE_TEST;
    task.taskPrio = TASK_PRIO_TEST - 1;

    ret = TEST_TaskCreate(&g_testTaskID01, &task);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    PRT_TaskLock();

    ret = PRT_SemPend(g_semID, OS_WAIT_FOREVER);
    ICUNIT_GOTO_EQUAL(ret, OS_ERRNO_SEM_PEND_IN_LOCK, ret, EXIT);

    PRT_TaskUnlock();

EXIT:
    (VOID)PRT_TaskDelete(g_testTaskID01);
    ret = PRT_SemDelete(g_semID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
}

VOID ItOsSem008(void)
{
    TEST_ADD_CASE("ItOsSem008", Testcase, TEST_OS, TEST_SEM, TEST_LEVEL0, TEST_FUNCTION);
}

