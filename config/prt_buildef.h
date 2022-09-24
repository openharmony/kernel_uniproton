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
 * Description: UniProton配置私有文件。
 */
#ifndef _PRT_BUILDEF_H
#define _PRT_BUILDEF_H

#ifdef OS_ARCH_ARMV7_M
#include "os_attr_armv7_m_external.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#ifndef OS_TSK_NUM_OF_PRIORITIES
#define OS_TSK_NUM_OF_PRIORITIES 63
#endif

#ifndef OS_TSK_PRIORITY_LOWEST
#define OS_TSK_PRIORITY_LOWEST (OS_TSK_NUM_OF_PRIORITIES - 1)
#endif

#ifndef OS_TSK_STACK_ADDR_ALIGN
#define OS_TSK_STACK_ADDR_ALIGN 16
#endif

#ifndef OS_REGISTER_ID
#define OS_REGISTER_ID 0
#endif

#ifndef OS_INIT_ID
#define OS_INIT_ID 1
#endif

#ifndef OS_TSK_CORE_BYTES_IN_PID
#define OS_TSK_CORE_BYTES_IN_PID 3
#endif

#undef OS_HARDWARE_PLATFORM
#define OS_HARDWARE_PLATFORM 4
#define OS_CORTEX_M4 4

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _PRT_BUILDEF_H */
