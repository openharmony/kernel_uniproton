/*
 * Copyright (c) 2022-2022 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 *    of conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 *    to endorse or promote products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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

#define OS_CORTEX_M4 4

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _PRT_BUILDEF_H */
