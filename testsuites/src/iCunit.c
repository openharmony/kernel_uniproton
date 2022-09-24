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
 * Description: UniProton基础测试框架。
 */
#include "iCunit.h"
#include "string.h"
#include "osTest.h"
#include "iCunit_config.h"

#include <stdio.h>

static ICuintCaseStatus g_iCunitCaseArray[ICUNIT_CASE_SIZE];
static TUINT32 g_iCunitInitSuccess = 0x0000FFFF;
static TUINT32 g_iCunitCaseFailedCnt = 0;
static TUINT32 g_iCunitErrLogAddCase = 0;

static TUINT16 g_iCunitErrLineNo;
static TUINTPTR g_iCunitErrCode;

static TUINT32 g_failResult;
static TUINT32 g_passResult;

static char *g_strLayer[] = {
    "OS", "CMSIS", "POSIX", "LIB", "VFS", "EXTEND",
    "PARTITION", "CPP", "SHELL", "LINUX", "USB", "DRIVERFRAME", "CONTEXTHUB"
};
static char *g_strModule[] = {
    "TASK", "MEM", "SEM", "MUX", "EVENT", "QUE", "SWTMR", "HWI", "ATO", "CPUP", "SCATTER", "RUNSTOP", "TIMER",
    "MMU", "TICKLESS", "ROBIN", "LIBC", "WAIT", "VFAT", "YAFFS", "JFFS", "RAMFS", "NFS", "PROC", "FS",
    "PTHREAD", "COMP", "HWI_HALFBOTTOM", "WORKQ", "WAKELOCK", "TIMES",
    "LIBM", "SUPPORT", "STL", "MAIL", "MSG", "CP", "SIGNAL", "SCHED", "MTDCHAR", "TIME", "WRITE", "READ",
    "DYNLOAD", "REGISTER", "SR", "UNAME", "ERR"
};
static char *g_strLevel[] = {
    "LEVEL0", "LEVEL1", "LEVEL2", "LEVEL3"
};
static char *g_strType[] = {
    "FUNCTION", "PRESSURE", "PERFORMANCE"
};

void ICunitSaveErr(TUINTPTR line, TUINTPTR retCode)
{
    g_iCunitErrLineNo = (g_iCunitErrLineNo == 0) ? line : g_iCunitErrLineNo;
    g_iCunitErrCode = (g_iCunitErrCode == 0) ? (TUINTPTR)retCode : g_iCunitErrCode;
}

TUINT32 ICunitAddCase(ICuintCaseStatus *arg)
{
    TUINT16 idx = 0;

    if (g_iCunitInitSuccess) {
        return (TUINT32)ICUNIT_UNINIT;
    }

    if (idx == ICUNIT_CASE_SIZE) {
        g_iCunitErrLogAddCase++;
        return (TUINT32)ICUNIT_CASE_FULL;
    }

    g_iCunitCaseArray[idx].pcCaseID = arg->pcCaseID;
    g_iCunitCaseArray[idx].caseFunc = arg->caseFunc;
    g_iCunitCaseArray[idx].testcaseLayer = arg->testcaseLayer;
    g_iCunitCaseArray[idx].testcaseModule = arg->testcaseModule;
    g_iCunitCaseArray[idx].testcaseLevel = arg->testcaseLevel;
    g_iCunitCaseArray[idx].testcaseType = arg->testcaseType;

    ICunitRun();
    return (TUINT32)ICUNIT_SUCCESS;
}

TUINT32 ICunitInit()
{
    g_iCunitInitSuccess = 0x0000;

    g_iCunitCaseFailedCnt = 0;

    g_iCunitErrLogAddCase = 0;

    (void)memset_s(g_iCunitCaseArray, sizeof(g_iCunitCaseArray), 0, sizeof(g_iCunitCaseArray));
    return (TUINT32)ICUNIT_SUCCESS;
}

TUINT32 ICunitRunF()
{
    TUINT32 idx, idx1;
    TUINT32 caseRet;

    ICuintCaseStatus *caseArray = g_iCunitCaseArray;
    idx1 = 1;

    for (idx = 0; idx < idx1; idx++, caseArray++) {
        g_iCunitErrLineNo = 0;
        g_iCunitErrCode = 0;

        caseRet = caseArray->caseFunc();
        caseArray->errLine = g_iCunitErrLineNo;
        caseArray->retCode = (g_iCunitErrLineNo == 0) ? (caseRet) : (g_iCunitErrCode);

        if ((g_iCunitErrLineNo == 0) && (caseRet == 0)) {
            g_passResult++;
            PRINTF("  [Passed]-%s-%s-%s-%s-%s\n", caseArray->pcCaseID, g_strLayer[caseArray->testcaseLayer],
                g_strModule[caseArray->testcaseModule], g_strLevel[caseArray->testcaseLevel],
                g_strType[caseArray->testcaseType]);
        } else {
            g_failResult++;
            g_iCunitCaseFailedCnt++;
            PRINTF("  [Failed]-%s-%s-%s-%s-%s-[Errline: %d RetCode:0x%lx]\n", caseArray->pcCaseID,
                g_strLayer[caseArray->testcaseLayer], g_strModule[caseArray->testcaseModule],
                g_strLevel[caseArray->testcaseLevel], g_strType[caseArray->testcaseType],
                caseArray->errLine, caseArray->retCode);
        }
    }

    return (TUINT32)ICUNIT_SUCCESS;
}

TUINT32 ICunitRun()
{
    if (g_iCunitInitSuccess) {
        return (TUINT32)ICUNIT_UNINIT;
    }

    ICunitRunF();

    return (TUINT32)ICUNIT_SUCCESS;
}

void ICunitTestResultGet(TUINT32 *passResult, TUINT32 *failResult)
{
    if (passResult != NULL) {
        *passResult = g_passResult;
    }
    if (failResult != NULL) {
        *failResult = g_failResult;
    }
}

