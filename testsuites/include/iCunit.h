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
#ifndef _LOS_ICUNIT_H
#define _LOS_ICUNIT_H

typedef unsigned short TUINT16;
typedef unsigned int TUINT32;
typedef signed short TINT16;
typedef signed long TINT32;
typedef char TCHAR;
typedef unsigned long TUINTPTR;

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif

#define FUNCTION_TEST (1 << 0)

#define PRESSURE_TEST (1 << 1)

#define PERFORMANCE_TEST (1 << 2)

#define TEST_MODE (FUNCTION_TEST)

typedef TUINT32 (*CASE_FUNCTION)(void);

typedef struct {
    TCHAR *pcCaseID;
    CASE_FUNCTION caseFunc;
    TUINT16 testcaseLayer;
    TUINT16 testcaseModule;
    TUINT16 testcaseLevel;
    TUINT16 testcaseType;
    TUINTPTR retCode;
    TUINT16 errLine;
} ICuintCaseStatus;

typedef enum {
    TEST_TASK = 0,
    TEST_MEM,
    TEST_SEM,
    TEST_MUX,
    TEST_EVENT,
    TEST_QUE,
    TEST_SWTMR,
    TEST_HWI,
    TEST_ATO,
    TEST_CPUP,
    TEST_SCATTER,
    TEST_RUNSTOP,
    TEST_TIMER,
    TEST_MMU,
    TEST_TICKLESS,
    TEST_ROBIN,
    TEST_LIBC,
    TEST_WAIT,
    TEST_VFAT,
    TEST_YAFFS,
    TEST_JFFS,
    TEST_RAMFS,
    TEST_NFS,
    TEST_PROC,
    TEST_FS,
    TEST_PTHREAD,
    TEST_COMP,
    TEST_HWI_HALFBOTTOM,
    TEST_WORKQ,
    TEST_WAKELOCK,
    TEST_TIMES,
    TEST_LIBM,
    TEST_SUPPORT,
    TEST_STL,
    TEST_MAIL,
    TEST_MSG,
    TEST_CP,
    TEST_SIGNAL,
    TEST_SCHED,
    TEST_MTDCHAR,
    TEST_TIME,
    TEST_WRITE,
    TEST_READ,
    TEST_DYNLOAD,
    TEST_REGISTER,
    TEST_SR,
    TEST_UNAME,
    TEST_MISC,
    TEST_EXC,
    TEST_DRIVERBASE,
    TEST_DYNLINK,
    TEST_LMS,
} OsTestModule;

typedef enum {
    TEST_OS = 0,
    TEST_CMSIS,
    TEST_POSIX,
    TEST_LIB,
    TEST_VFS,
    TEST_EXTEND,
    TEST_PARTITION,
    TEST_CPP,
    TEST_SHELL,
    TEST_LINUX,
    TEST_USB,
    TEST_DRIVERFRAME,
    TEST_CONTEXHUB
} OsTestLayer;

typedef enum {
    TEST_LEVEL0 = 0,
    TEST_LEVEL1,
    TEST_LEVEL2,
    TEST_LEVEL3
} OsTestLevel;

typedef enum {
    TEST_FUNCTION = 0,
    TEST_PRESSURE,
    TEST_PERFORMANCE
} OsTestType;

extern void ICunitSaveErr(TUINTPTR line, TUINTPTR retCode);

#define ICUNIT_UNINIT 0x0EF00000
#define ICUNIT_OPENFILE_FAILED 0x0EF00001
#define ICUNIT_ALLOC_FAIL 0x0EF00002
#define ICUNIT_SUIT_FULL 0x0EF00002
#define ICUNIT_CASE_FULL 0x0EF00003
#define ICUNIT_SUIT_ALL 0x0EF0FFFF

#define ICUNIT_SUCCESS 0x00000000

#define ICUNIT_TRACK_EQUAL(param, value, retcode) do { \
    if ((param) != (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
    }                                                 \
} while (0)

#define ICUNIT_TRACK_NOT_EQUAL(param, value, retcode) do { \
    if ((param) == (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
    }                                                 \
} while (0)

#define ICUNIT_ASSERT_EQUAL_VOID(param, value, retcode) do { \
    if ((param) != (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
        return;                                       \
    }                                                 \
} while (0)

#define ICUNIT_ASSERT_NOT_EQUAL_VOID(param, value, retcode) do { \
    if ((param) == (value)) {                           \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));   \
        return;                                         \
    }                                                   \
} while (0)
#define ICUNIT_ASSERT_EQUAL(param, value, retcode) do { \
    if ((param) != (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
        return 1;                                     \
    }                                                 \
} while (0)

#define ICUNIT_ASSERT_NOT_EQUAL(param, value, retcode) do { \
    if ((param) == (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
        return 1;                                     \
    }                                                 \
} while (0)

#define ICUNIT_ASSERT_WITHIN_EQUAL(param, value1, value2, retcode) do { \
    if ((param) < (value1) || (param) > (value2)) {            \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));          \
        return 1;                                              \
    }                                                          \
} while (0)

#define ICUNIT_ASSERT_WITHIN_EQUAL_VOID(param, value1, value2, retcode) do { \
    if ((param) < (value1) || (param) > (value2)) {                 \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));               \
        return;                                                     \
    }                                                               \
} while (0)

#define ICUNIT_ASSERT_EQUAL_VOID(param, value, retcode) do { \
    if ((param) != (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
        return;                                       \
    }                                                 \
} while (0)

#define ICUNIT_ASSERT_SIZE_STRING_EQUAL(str1, str2, strsize, retcode) do { \
    if (strncmp((str1), (str2), (strsize)) != 0) {                \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));             \
        return 1;                                                 \
    }                                                             \
} while (0)

#define ICUNIT_ASSERT_STRING_EQUAL(str1, str2, retcode) do { \
    if (strcmp((str1), (str2)) != 0) {                \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
        return 1;                                     \
    }                                                 \
} while (0)

#define ICUNIT_ASSERT_STRING_EQUAL_VOID(str1, str2, retcode) do {  \
    if (strcmp((const char *)(str1), (const char *)(str2)) != 0) { \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));              \
        return;                                                    \
    }                                                              \
} while (0)

#define ICUNIT_ASSERT_STRING_NOT_EQUAL(str1, str2, retcode) do { \
    if (strcmp((str1), (str2)) == 0) {                  \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));   \
        return 1;                                       \
    }                                                   \
} while (0)

#define ICUNIT_GOTO_EQUAL(param, value, retcode, label) do { \
    if ((param) != (value)) {                         \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode)); \
        goto label;                                   \
    }                                                 \
} while (0)

#define ICUNIT_GOTO_NOT_EQUAL(param, value, retcode, label) do { \
    if ((param) == (value)) {                           \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));   \
        goto label;                                     \
    }                                                   \
} while (0)

#define ICUNIT_GOTO_STRING_EQUAL(str1, str2, retcode, label) do { \
    if (strcmp((str1), (str2)) != 0) {                   \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));    \
        goto label;                                      \
    }                                                    \
} while (0)

#define ICUNIT_GOTO_STRING_NOT_EQUAL(str1, str2, retcode, label) do { \
    if (strcmp((str1), (str2)) == 0) {                       \
        ICunitSaveErr(__LINE__, (TUINTPTR)(retcode));        \
        goto label;                                          \
    }                                                        \
} while (0)

extern TUINT32 ICunitAddCase(ICuintCaseStatus *arg);
extern TUINT32 ICunitRun(void);
extern TUINT32 ICunitInit(void);
extern TUINT32 iCunitPrintReport(void);

#define TEST_ADD_CASE(name, casefunc, layer, module, level, type) do {          \
    ICuintCaseStatus arg = { name, casefunc, layer, module, level, type, 0, 0}; \
    TUINT32 ret = ICunitAddCase(&arg);                                          \
    ICUNIT_ASSERT_EQUAL_VOID(ret, ICUNIT_SUCCESS, ret);                         \
} while (0)

#define TEST_RUN_SUITE() do {                                        \
    TUINT32 ret = ICunitRun();                                       \
    ICUNIT_ASSERT_NOT_EQUAL_VOID(ret, ICUNIT_UNINIT, ICUNIT_UNINIT); \
} while (0)

extern void ICunitTestResultGet(TUINT32 *passResult, TUINT32 *failResult);
#endif /* _UNI_ICUNIT_H */
