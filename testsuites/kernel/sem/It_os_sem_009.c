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

static UINT32 g_testTsk = 0;
static SemHandle g_usSemID = 0;

static VOID TaskF01(void)
{
    UINT32 ret;

    g_testCount++;
    ret = PRT_SemPend(g_usSemID, OS_WAIT_FOREVER);
    ICUNIT_ASSERT_EQUAL_VOID(ret, OS_OK, ret);

    g_testTsk = 1;
    g_testCount++;

    PRT_TaskDelete(g_testTaskID01);
}
static VOID TaskF02(void)
{
    UINT32 ret;

    g_testCount++;
    ret = PRT_SemPend(g_usSemID, OS_WAIT_FOREVER);
    ICUNIT_ASSERT_EQUAL_VOID(ret, OS_OK, ret);

    g_testTsk = 2; // 2, The flag of test task.
    g_testCount++;

    PRT_TaskDelete(g_testTaskID02);
}

static UINT32 Testcase(VOID)
{
    UINT32 ret;
    struct TskInitParam task = { 0 };

    task.taskEntry = (TskEntryFunc)TaskF01;
    task.name = "Sem12";
    task.stackSize = TASK_STACK_SIZE_TEST;
    task.taskPrio = TASK_PRIO_TEST - 1;

    g_testCount = 0;
    g_testTsk = 0;

    ret = PRT_SemCreate(0, &g_usSemID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ret = TEST_TaskCreate(&g_testTaskID01, &task);
    ICUNIT_GOTO_EQUAL(ret, OS_OK, ret, EXIT);

    ICUNIT_GOTO_EQUAL(g_testCount, 1, g_testCount, EXIT1);

    task.taskEntry = (TskEntryFunc)TaskF02;
    task.name = "Sem12_1";
    task.taskPrio = TASK_PRIO_TEST - 3; // 3, set new task priority, it is higher than the current task.

    ret = TEST_TaskCreate(&g_testTaskID02, &task);
    ICUNIT_GOTO_EQUAL(ret, OS_OK, ret, EXIT1);

    ICUNIT_GOTO_EQUAL(g_testCount, 2, g_testCount, EXIT2); // 2, Here, assert that g_testCount is equal to 2.

    ICUNIT_GOTO_EQUAL(g_testTsk, 0, g_testTsk, EXIT3);

    ret = PRT_SemPost(g_usSemID);
    ICUNIT_GOTO_EQUAL(ret, OS_OK, ret, EXIT2);

    PRT_TaskDelay(1);

    ICUNIT_GOTO_EQUAL(g_testTsk, 1, g_testTsk, EXIT3);
    ICUNIT_GOTO_EQUAL(g_testCount, 3, g_testCount, EXIT2); // 3, Here, assert that g_testCount is equal to 3.

    PRT_TaskDelete(g_testTaskID02);

    ret = PRT_SemDelete(g_usSemID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;

EXIT2:
    PRT_TaskDelete(g_testTaskID02);
EXIT1:
    PRT_TaskDelete(g_testTaskID01);
EXIT:
    ret = PRT_SemDelete(g_usSemID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
EXIT3:
    PRT_TaskDelete(g_testTaskID02);
    ret = PRT_SemDelete(g_usSemID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
}

VOID ItOsSem009()
{
    TEST_ADD_CASE("ItOsSem009", Testcase, TEST_OS, TEST_SEM, TEST_LEVEL1, TEST_FUNCTION);
}

