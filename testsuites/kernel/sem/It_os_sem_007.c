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

