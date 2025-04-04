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
 * Description: UniProton hi3093 demo
 */
#ifndef __DW_UART_CORE_H__
#define __DW_UART_CORE_H__

#include "uart_regs.h"
#include "common.h"

#define MAX_UART_NUM          8

extern S32 uart_reg_read(S32 uart_num, U32 offset, U32 *val); 
extern void uart_reg_write(S32 uart_num, U32 offset, U32 val); 
extern void uart_set_dll_dlh(S32 uart_num, U32 dll, U32 dlh);
extern void uart_get_dll_dlh(S32 uart_num, U32 *dll, U32 *dlh);
extern void uart_set_fifo_ctrl(S32 uart_num, U32 fifo_ctrl);
extern void uart_set_lcr(S32 uart_num, U32 lcr);
extern void uart_set_irq_enable(S32 uartno, U32 value);
extern S32 uart_is_txfifo_full(S32 uart_num);
extern S32 uart_is_rx_ready(S32 uart_num);
extern void uart_tx_char(S32 uart_num, const S8 c); 
extern void uart_rx_char(S32 uart_num, S8 *c); 
extern S32 uart_wait4idle(S32 uartno, U32 timeout);

#endif /* __DW_UART_CORE_H__ */