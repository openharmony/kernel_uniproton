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
 * Create: 2022-11-15
 * Description: errno功能实现
 */

#include <errno.h>
#include "prt_task_external.h"

/* the specific errno get or set in interrupt service routine */
static int g_isrErrno;

int *__errno(void)
{
    struct TagTskCb *runTask;

    if (OS_INT_INACTIVE) {
        runTask = RUNNING_TASK;
        return &runTask->lastErr;
    } else {
        return &g_isrErrno;
    }
}
