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

static UINT32 Testcase(VOID)
{
    UINT32 ret;
    SemHandle semID = 0;

    ret = PRT_SemCreate(0, &semID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ret = PRT_SemPost(semID);
    ICUNIT_TRACK_EQUAL(ret, OS_OK, ret);

    ret = PRT_SemDelete(semID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ret = PRT_SemCreate(OS_SEM_COUNT_MAX, &semID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    ret = PRT_SemPost(semID);
    ICUNIT_TRACK_EQUAL(ret, OS_ERRNO_SEM_OVERFLOW, ret);

    ret = PRT_SemDelete(semID);
    ICUNIT_ASSERT_EQUAL(ret, OS_OK, ret);

    return OS_OK;
}

VOID ItOsSem005(void)
{
    TEST_ADD_CASE("ItOsSem005", Testcase, TEST_OS, TEST_SEM, TEST_LEVEL0, TEST_FUNCTION);
}

