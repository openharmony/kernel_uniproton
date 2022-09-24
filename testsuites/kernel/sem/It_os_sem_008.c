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
 * Description: UniProton 信号量测试用例。
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

