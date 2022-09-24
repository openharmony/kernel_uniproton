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
 * Description: UniProton 任务测试用例。
 */
#include "osTest.h"
#include "It_os_task.h"

static VOID TaskF04(UINT32 arg)
{
    ICUNIT_ASSERT_EQUAL_VOID(arg, 1, arg);
    g_testCount++;
    return;
}

static VOID TaskF03(UINT32 arg)
{
    ICUNIT_ASSERT_EQUAL_VOID(arg, -1, arg);
    g_testCount++;
    return;
}

static VOID TaskF02(UINT32 arg)
{
    ICUNIT_ASSERT_EQUAL_VOID(arg, 0, arg);
    g_testCount++;
    return;
}

static VOID TaskF01(UINT32 arg)
{
    ICUNIT_ASSERT_EQUAL_VOID(arg, 0xffff, arg); // 0xffff, Here, assert that uwArg is equal to 0xffff.
    g_testCount++;
    return;
}

static UINT32 TestCase(VOID)
{
    UINT32 ret;
    struct TskInitParam task1 = { 0 };
    task1.taskEntry = (TskEntryFunc)TaskF01;
    task1.stackSize = TASK_STACK_SIZE_TEST;
    task1.name = "Tsk016A";
    task1.taskPrio = TASK_PRIO_TEST - 1;
    task1.reserved = 0;
    task1.args[0] = 0xffff; // 0xffff, Used to verify incoming parameter.

    g_testCount = 0;
    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ICUNIT_ASSERT_EQUAL(g_testCount, 1, g_testCount);

    task1.taskEntry = (TskEntryFunc)TaskF02;
    task1.args[0] = 0;
    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ICUNIT_ASSERT_EQUAL(g_testCount, 2, g_testCount); // 2, Here, assert that g_testCount is equal to 2.

    task1.taskEntry = (TskEntryFunc)TaskF03;
    task1.args[0] = -1;
    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ICUNIT_ASSERT_EQUAL(g_testCount, 3, g_testCount); // 3, Here, assert that g_testCount is equal to 3.

    task1.taskEntry = (TskEntryFunc)TaskF04;
    task1.args[0] = 1;
    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ICUNIT_ASSERT_EQUAL(g_testCount, 4, g_testCount); // 4, Here, assert that g_testCount is equal to 4.

    return OS_OK;
}

VOID ItOsTask016(VOID)
{
    TEST_ADD_CASE("ItOsTask016", TestCase, TEST_OS, TEST_TASK, TEST_LEVEL0, TEST_FUNCTION);
}

