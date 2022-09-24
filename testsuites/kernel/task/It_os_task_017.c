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

static VOID TaskF01(VOID)
{
    g_testCount++;
    return;
}

static UINT32 TestCase(VOID)
{
    UINT32 ret;
    struct TskInitParam task1 = { 0 };
    task1.taskEntry = (TskEntryFunc)TaskF01;
    task1.stackSize = TASK_STACK_SIZE_TEST;
    task1.name = "Tsk017A";
    task1.taskPrio = 1;

    g_testCount = 0;

    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ICUNIT_GOTO_EQUAL(g_testCount, 1, g_testCount, EXIT);
    ret = PRT_TaskDelete(g_testTaskID01);
    ICUNIT_ASSERT_EQUAL(ret, OS_ERRNO_TSK_NOT_CREATED, ret);
    return OS_OK;

EXIT:
    PRT_TaskDelete(g_testTaskID01);
    return OS_OK;
}

VOID ItOsTask017(VOID)
{
    TEST_ADD_CASE("ItOsTask017", TestCase, TEST_OS, TEST_TASK, TEST_LEVEL0, TEST_FUNCTION);
}

