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
#include <stdarg.h>
#include "prt_typedef.h"
#include "cpu_config.h"
#include "securec.h"
#include "serial.h"
#include "prt_hwi.h"

typedef U32 (*PrintFunc)(const char *format, va_list vaList);
#define OS_MAX_SHOW_LEN 0x200

U32 uart_recv(U8 *value)
{
    S32 ret = 0;
    ret = serial_getc();
    if (ret == -EAGAIN) {
        return EAGAIN;
    }

    *value = (U8)ret;

    return 0;
}

void uart_recv_hwi(void) 
{
    U8 data;
    while (uart_recv(&data) == 0) {
        /*Do not printf in this task*/
    }
}

U32 PRT_UartInit(void)
{

    U32 ret;
    (void)PRT_HwiDelete(CCORE_SYS_UART4_INTID);

    ret = PRT_HwiSetAttr(CCORE_SYS_UART4_INTID, 12, OS_HWI_MODE_ENGROSS);
    if (ret != OS_OK) {
        return ret;
    }

    ret = PRT_HwiCreate(CCORE_SYS_UART4_INTID, (HwiProcFunc)uart_recv_hwi, CCORE_SYS_UART4_INTID);
    if (ret != OS_OK) {
        return ret;
    }

    ret = PRT_HwiEnable(CCORE_SYS_UART4_INTID);
    if (ret != OS_OK) {
        return ret;
    }

    serial_init(&g_uart_cfg, &g_uart_ops);

    return OS_OK;
}

void uart_poll_send(unsigned char ch)
{
    serial_putc((char)ch);
}

void TestPutc(unsigned char ch)
{
    uart_poll_send(ch);
    if (ch == '\n') {
        uart_poll_send('\r');
    }
}

int TestPrintf(const char *format, va_list vaList)
{
    int len;
    char buff[OS_MAX_SHOW_LEN] = {0};
    char *str = buff;
    
    len = vsnprintf_s(buff, OS_MAX_SHOW_LEN, OS_MAX_SHOW_LEN, format, vaList);
    if (len == -1) {
        return len;
    }
    
    while (*str != '\0') {
        TestPutc(*str);
        str++;
    }
    
    return OS_OK;
}

U32 PRT_Printf(const char *format, ...)
{
    va_list vaList;
    S32 count;
    
    va_start(vaList, format);
    count = TestPrintf(format, vaList);
    va_end(vaList);
    
    return count;
}

U32 PRT_PrintfInit()
{
    U32 ret;

    ret = PRT_UartInit();
    if (ret != OS_OK) {
        return ret;
    }

    return OS_OK;
}
