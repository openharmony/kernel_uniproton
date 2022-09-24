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
#ifndef PRT_CONFIG_H
#define PRT_CONFIG_H

#include "prt_buildef.h"
#include "prt_typedef.h"

#ifdef OS_DEVICE_CONFIG
#include "target_config.h"
#endif

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* ***************************** 配置系统基本信息 ******************************* */
/* 芯片主频 */
#ifndef OS_SYS_CLOCK
#define OS_SYS_CLOCK                                    0
#endif

/* ***************************** 中断模块配置 ************************** */
/* 硬中断最大支持个数 */
#ifndef OS_HWI_MAX_NUM_CONFIG
#define OS_HWI_MAX_NUM_CONFIG                           150
#endif

/* ***************************** 配置Tick中断模块 *************************** */
/* Tick中断模块裁剪开关 */
#ifndef OS_INCLUDE_TICK
#define OS_INCLUDE_TICK                                 YES
#endif

/* Tick中断时间间隔，tick处理时间不能超过1/OS_TICK_PER_SECOND(s) */
#ifndef OS_TICK_PER_SECOND
#define OS_TICK_PER_SECOND                              5000
#endif

/* ***************************** 配置定时器模块 ***************************** */
/* 基于TICK的软件定时器裁剪开关 */
#ifndef OS_INCLUDE_TICK_SWTMER
#define OS_INCLUDE_TICK_SWTMER                          NO
#endif

/* 基于TICK的软件定时器最大个数 */
#ifndef OS_TICK_SWITIMER_MAX_NUM
#define OS_TICK_SWITIMER_MAX_NUM                        8
#endif

/* ***************************** 配置任务模块 ******************************* */
/* 任务模块裁剪开关 */
#ifndef OS_INCLUDE_TASK
#define OS_INCLUDE_TASK                                 YES
#endif
/* 最大支持的任务数,最大共支持254个 */
#ifndef OS_TSK_MAX_SUPPORT_NUM
#define OS_TSK_MAX_SUPPORT_NUM                          8
#endif
/* 缺省的任务栈大小 */
#ifndef OS_TSK_DEFAULT_STACK_SIZE
#define OS_TSK_DEFAULT_STACK_SIZE                       0x800
#endif
/* IDLE任务栈的大小 */
#ifndef OS_TSK_IDLE_STACK_SIZE
#define OS_TSK_IDLE_STACK_SIZE                          0x800
#endif
/* 任务栈初始化魔术字，默认是0xCA，只支持配置一个字节 */
#ifndef OS_TSK_STACK_MAGIC_WORD
#define OS_TSK_STACK_MAGIC_WORD                         0xCA
#endif

/* ***************************** 配置CPU占用率及CPU告警模块 **************** */
/* CPU占用率模块裁剪开关 */
#ifndef OS_INCLUDE_CPUP
#define OS_INCLUDE_CPUP                                 NO
#endif
/* 采样时间间隔(单位tick)，若其值大于0，则作为采样周期，否则两次调用PRT_CpupNow或PRT_CpupThread间隔作为周期 */
#ifndef OS_CPUP_SAMPLE_INTERVAL
#define OS_CPUP_SAMPLE_INTERVAL                         0
#endif
/* CPU占用率告警动态配置项 */
#ifndef OS_CONFIG_CPUP_WARN
#define OS_CONFIG_CPUP_WARN                             NO
#endif
/* CPU占用率告警阈值(精度为万分比) */
#ifndef OS_CPUP_SHORT_WARN
#define OS_CPUP_SHORT_WARN                              0
#endif
/* CPU占用率告警恢复阈值(精度为万分比) */
#ifndef OS_CPUP_SHORT_RESUME
#define OS_CPUP_SHORT_RESUME                            0
#endif

/* ***************************** 配置内存管理模块 ************************** */
/* 用户可以创建的最大分区数，取值范围[0,253] */
#ifndef OS_MEM_MAX_PT_NUM
#define OS_MEM_MAX_PT_NUM                               10
#endif
/* 私有FSC内存分区起始地址 */
#ifndef OS_MEM_FSC_PT_ADDR
#define OS_MEM_FSC_PT_ADDR                              NULL
#endif
/* 私有FSC内存分区大小 */
#ifndef OS_MEM_FSC_PT_SIZE
#define OS_MEM_FSC_PT_SIZE                              0
#endif

/* ***************************** 配置信号量管理模块 ************************* */
/* 信号量模块裁剪开关 */
#ifndef OS_INCLUDE_SEM
#define OS_INCLUDE_SEM                                  NO
#endif
/* 最大支持的信号量数 */
#ifndef OS_SEM_MAX_SUPPORT_NUM
#define OS_SEM_MAX_SUPPORT_NUM                          0
#endif

/* ***************************** 配置队列模块 ******************************* */
/* 队列模块裁剪开关 */
#ifndef OS_INCLUDE_QUEUE
#define OS_INCLUDE_QUEUE                                NO
#endif
/* 最大支持的队列数,范围(0,0xFFFF] */
#ifndef OS_QUEUE_MAX_SUPPORT_NUM
#define OS_QUEUE_MAX_SUPPORT_NUM                        10
#endif

/* ************************* 钩子模块配置 *********************************** */
/* 硬中断进入钩子最大支持个数, 范围[0, 255] */
#ifndef OS_HOOK_HWI_ENTRY_NUM
#define OS_HOOK_HWI_ENTRY_NUM                           0
#endif
/* 硬中断退出钩子最大支持个数, 范围[0, 255] */
#ifndef OS_HOOK_HWI_EXIT_NUM
#define OS_HOOK_HWI_EXIT_NUM                            0
#endif
/* 任务切换钩子最大支持个数, 范围[0, 255] */
#ifndef OS_HOOK_TSK_SWITCH_NUM
#define OS_HOOK_TSK_SWITCH_NUM                          0
#endif
/* IDLE钩子最大支持个数, 范围[0, 255] */
#ifndef OS_HOOK_IDLE_NUM
#define OS_HOOK_IDLE_NUM                                0
#endif

/* 启动模块，系统支持的启动层级，最小为两级, 该枚举由具体产品定义 */
#ifndef OS_DEVICE_CONFIG
typedef enum OsinitPhaseId {
    OS_MOUDLE_REG,
    OS_MOUDLE_INIT,
    OS_MOUDLE_CONFIG,
};
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cpluscplus */
#endif /* __cpluscplus */

#endif /* PRT_CONFIG_H */
