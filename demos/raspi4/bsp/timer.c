/*
 * Copyright (c) 2009-2022 Huawei Technologies Co., Ltd. All rights reserved.
 *
 * UniProton is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 * Create: 2009-12-22
 * Description: UniProton raspi4 demo
 */
#include "prt_sys.h"
#include "prt_tick.h"
#include "prt_config.h"
#include "prt_task.h"
#include "prt_hwi.h"
#include "cpu_config.h"
#include "securec.h"

U64 g_timerFrequency;
#define PMU_TIMER_FREQUENCY g_timerFrequency

U64 GetGenericTimerFreq(void)
{
    U64 freq;

    OS_EMBED_ASM("MRS %0, CNTFRQ_EL0" : "=r"(freq) : : "memory", "cc");
    
    return freq;
}

void TimerIsr(uintptr_t para)
{
    (void)para;
    U32 cfgMask = 0x0;
    U64 cycle = PMU_TIMER_FREQUENCY / OS_TICK_PER_SECOND;
    
    OS_EMBED_ASM("MSR CNTP_CTL_EL0, %0" : : "r"(cfgMask) : "memory");
    PRT_ISB();
    OS_EMBED_ASM("MSR CNTP_TVAL_EL0, %0" : : "r"(cycle) : "memory", "cc");
    
    cfgMask = 0x1;
    OS_EMBED_ASM("MSR CNTP_CTL_EL0, %0" : : "r"(cfgMask) : "memory");
    
    PRT_TickISR();
    PRT_ISB();
}

void CoreTimerInit(void)
{
    U32 cfgMask = 0x0;
    U64 cycle = PMU_TIMER_FREQUENCY / OS_TICK_PER_SECOND;
    
    OS_EMBED_ASM("MSR CNTP_CTL_EL0, %0" : : "r"(cfgMask) : "memory");
    PRT_ISB();
    OS_EMBED_ASM("MSR CNTP_TVAL_EL0, %0" : : "r"(cycle) : "memory", "cc");
    
    cfgMask = 0x1;
    OS_EMBED_ASM("MSR CNTP_CTL_EL0, %0" : : "r"(cfgMask) : "memory");
}

U32 CoreTimerStart(void)
{
    g_timerFrequency = GetGenericTimerFreq();
    CoreTimerInit();
    
    return OS_OK;
}

U32 TestClkStart(void)
{
    U32 ret;
    
    ret = PRT_HwiSetAttr(TEST_CLK_INT, 10, OS_HWI_MODE_ENGROSS);
    if (ret != OS_OK) {
        return ret;
    }
    
    ret = PRT_HwiCreate(TEST_CLK_INT, (HwiProcFunc)TimerIsr, 0);
    if (ret != OS_OK) {
        return ret;
    }
    
#if (OS_GIC_VER == 3)
    ret = PRT_HwiEnable(TEST_CLK_INT);
    if (ret != OS_OK) {
        return ret;
    }
#elif (OS_GIC_VER == 2)
    IsrRegister(TEST_CLK_INT, 0xaU, (0x1U << 0x3U));
#endif

    ret = CoreTimerStart();
    if (ret != OS_OK) {
        return ret;
    }
    
    return OS_OK;
}
