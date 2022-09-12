/*
 * Copyright (c) 2022-2022 Huawei Device Co., Ltd. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
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

#include "osTest.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define SELF_DELETED 0
#define SYS_EXIST_SWTMR 1

#define TEST_HWI_RUNTIME 0x100000
#define TASK_LOOP_NUM 0x100000

#define TASK_NAME_NUM 10
#define IT_TASK_LOOP 20

extern U32 g_stEventCB;
extern U32 g_stEventCB1;
extern U32 g_stEventCB2;
extern U32 g_stEventCB3;

extern VOID ItOsTask001(VOID);
extern VOID ItOsTask002(VOID);
extern VOID ItOsTask003(VOID);
extern VOID ItOsTask004(VOID);
extern VOID ItOsTask005(VOID);
extern VOID ItOsTask006(VOID);
extern VOID ItOsTask007(VOID);
extern VOID ItOsTask008(VOID);
extern VOID ItOsTask010(VOID);
extern VOID ItOsTask011(VOID);
extern VOID ItOsTask012(VOID);
extern VOID ItOsTask013(VOID);
extern VOID ItOsTask014(VOID);
extern VOID ItOsTask015(VOID);
extern VOID ItOsTask016(VOID);
extern VOID ItOsTask017(VOID);
extern VOID ItOsTask018(VOID);
extern VOID ItOsTask019(VOID);
extern VOID ItOsTask020(VOID);
extern VOID ItOsTask021(VOID);
extern VOID ItOsTask022(VOID);
extern VOID ItOsTask023(VOID);
extern VOID ItOsTask024(VOID);
extern VOID ItOsTask025(VOID);
extern VOID ItOsTask026(VOID);
extern VOID ItOsTask027(VOID);
extern VOID ItOsTask028(VOID);
extern VOID ItOsTask029(VOID);
extern VOID ItOsTask030(VOID);
extern VOID ItOsTask031(VOID);
extern VOID ItOsTask032(VOID);
extern VOID ItOsTask033(VOID);
extern VOID ItOsTask034(VOID);
extern VOID ItOsTask035(VOID);
extern VOID ItOsTask036(VOID);
extern VOID ItOsTask037(VOID);
extern VOID ItOsTask038(VOID);

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */
