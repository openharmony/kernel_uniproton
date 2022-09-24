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
 * Description: UniProton 事件测试用例。
 */
#include "osTest.h"
#include "It_os_event.h"

static VOID TaskF01(VOID)
{
    UINT32 events = 0;
    UINT32 ret;

    g_testCount++;
    ret = PRT_EventRead(0x11, OS_EVENT_ALL | OS_EVENT_WAIT, 3, &events); // 3, The timeout period for reading events.
    ICUNIT_GOTO_EQUAL(ret, OS_ERRNO_EVENT_READ_TIMEOUT, ret, EXIT);

    ICUNIT_ASSERT_EQUAL_VOID(g_testCount, 2, g_testCount); // 2, Here, assert that g_testCount is equal to 2.
    g_testCount++;

    ret = PRT_EventRead(0x4, OS_EVENT_ALL | OS_EVENT_WAIT, OS_EVENT_WAIT_FOREVER, &events);
    ICUNIT_ASSERT_EQUAL_VOID(ret, OS_OK, ret);

    g_testCount++;

EXIT:
    PRT_TaskDelete(g_testTaskID01);
}

static UINT32 Testcase(VOID)
{
    UINT32 ret;
    struct TskInitParam task1 = {0};
    task1.taskEntry = (TskEntryFunc)TaskF01;
    task1.name = "EventTsk2";
    task1.stackSize = TASK_STACK_SIZE_TEST;
    task1.taskPrio = TASK_PRIO_TEST - 2; // 2, set new task priority, it is higher than the test task.
    task1.reserved = 0;

    g_testCount = 0;
    ret = TEST_TaskCreate(&g_testTaskID01, &task1);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ICUNIT_ASSERT_EQUAL(g_testCount, 1, g_testCount);
    g_testCount++;

    PRT_EventWrite(g_testTaskID01, 0x2);

    PRT_TaskDelay(3); // 3, set delay time.

    ICUNIT_ASSERT_EQUAL(g_testCount, 3, g_testCount); // 3, Here, assert that g_testCount is equal to 3.
    g_testCount++;

    PRT_EventWrite(g_testTaskID01, 0x11);

    PRT_TaskDelay(4); // 4, set delay time.

    ICUNIT_ASSERT_EQUAL(g_testCount, 4, g_testCount); // 4, Here, assert that g_testCount is equal to 4.

    ret = PRT_TaskDelete(g_testTaskID01);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
}

VOID ItOsEvent002(VOID)
{
    TEST_ADD_CASE("ItOsEvent002", Testcase, TEST_OS, TEST_EVENT, TEST_LEVEL1, TEST_FUNCTION);
}
