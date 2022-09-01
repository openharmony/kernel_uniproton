/*
 * Copyright (c) 2021 Bestechnic (Shanghai) Co., Ltd. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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
#define OS_INIT_ID     1
#endif

#ifndef OS_TSK_CORE_BYTES_IN_PID
#define OS_TSK_CORE_BYTES_IN_PID 3
#endif

#ifndef OS_MOUDLE_CONFIG
#define OS_MOUDLE_CONFIG 2
#endif

#define OS_CORTEX_M4 4

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _PRT_BUILDEF_H */
