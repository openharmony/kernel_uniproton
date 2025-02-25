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
#ifndef CPU_CONFIG_H
#define CPU_CONFIG_H

#include "cache_asm.h"

#define MMU_IMAGE_ADDR             0x7A000000ULL
#define MMU_GIC_ADDR               0xFF800000ULL
#define MMU_UART_ADDR              0xFE200000ULL
#define MMU_OPENAMP_ADDR           0x70000000ULL

#define UART_BASE_ADDR             0xFE201000ULL

#define TEST_CLK_INT               30

#define OS_GIC_VER                 2
#define SICR_ADDR_OFFSET_PER_CORE  0x200U
#define GIC_REG_BASE_ADDR          0xFF841000ULL

#define GIC_DIST_BASE              GIC_REG_BASE_ADDR
#define GIC_CPU_BASE               (GIC_DIST_BASE + 0x1000U)

#define GICD_CTLR                  (GIC_DIST_BASE + 0x0000U)
#define GICD_TYPER                 (GIC_DIST_BASE + 0x0004U)
#define GICD_IIDR                  (GIC_DIST_BASE + 0x0008U)
#define GICD_IGROUPRn              (GIC_DIST_BASE + 0x0080U)
#define GICD_ISENABLERn            (GIC_DIST_BASE + 0x0100U)
#define GICD_ICENABLERn            (GIC_DIST_BASE + 0x0180U)
#define GICD_ISPENDRn              (GIC_DIST_BASE + 0x0200U)
#define GICD_ICPENDRn              (GIC_DIST_BASE + 0x0280U)
#define GICD_ISACTIVERn            (GIC_DIST_BASE + 0x0300U)
#define GICD_ICACTIVERn            (GIC_DIST_BASE + 0x0380U)
#define GICD_IPRIORITYn            (GIC_DIST_BASE + 0x0400U)

#define GICC_CTLR                  (GIC_CPU_BASE  + 0x0000U)
#define GICC_PMR                   (GIC_CPU_BASE  + 0x0004U)

#define BIT(n)                     (1 << (n))

#define GICC_CTLR_ENABLEGRP0       BIT(0)
#define GICC_CTLR_ENABLEGRP1       BIT(1)
#define GICC_CTLR_FIQBYPDISGRP0    BIT(5)
#define GICC_CTLR_IRQBYPDISGRP0    BIT(6)
#define GICC_CTLR_FIQBYPDISGRP1    BIT(7)
#define GICC_CTLR_IRQBYPDISGRP1    BIT(8)

#define GICC_CTLR_ENABLE_MASK      (GICC_CTLR_ENABLEGRP0 | \
                                    GICC_CTLR_ENABLEGRP1)

#define GICC_CTLR_BYPASS_MASK      (GICC_CTLR_FIQBYPDISGRP0 | \
                                    GICC_CTLR_IRQBYPDISGRP0 | \
                                    GICC_CTLR_FIQBYPDISGRP1 | \
                                    GICC_CTLR_IRQBYPDISGRP1)    

#define GIC_REG_READ(addr)         (*(volatile U32 *)((uintptr_t)(addr)))
#define GIC_REG_WRITE(data, addr)  (*(volatile U32 *)((uintptr_t)(addr)) = (U32)(data))

#endif
