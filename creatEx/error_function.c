/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2017.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU Lesser General Public License as published   *
* by the Free Software Foundation, either version 3 or (at your option)   *
* any later version. This program is distributed without any warranty.    *
* See the files COPYING.lgpl-v3 and COPYING.gpl-v3 for details.           *
\*************************************************************************/

/* Listing 3-3 */

#include <stdarg.h>
#include "error_functions.h"
#include "tlpi_hdr.h"
#include "ename.c.inc"          /* Defines ename and MAX_ENAME */

#ifdef __GNUC__
__attribute__ ((__noreturn__))
#endif



static void terminate(Boolean useExit3)
{
    char *s;

/*	EF_DUMPCORE 환경 변수가 비어 있지 않은 문자열로 정의되어 있으면
	코어를 덤프하고, 그렇지 않으면 'useExit3'의 값에 따라 exit(3)이나
	_exit(2)를 호출한다.
	*/

    s = getenv("EF_DUMPCORE");// 환경변수 값을 구해오는 함수

    if (s != NULL && *s != '\0')
        abort();//프로그램을 종료하기 전에 버퍼를 삭제하고 열린 파일을 닫음
    else if (useExit3)
        exit(EXIT_FAILURE); //비정상 종료
    else
        _exit(EXIT_FAILURE);
/*
	_exit(); 호출하면 곧바로 커널로 복귀하지만, exit(); 함수를
	사용하면 버퍼를 비운다던지, 기타 루틴을 수행후에 커널로
	복귀합니다.
*/
}

static void outputError(Boolean useErr, int err, Boolean flushStdout, const char *format, va_list ap)
{
#define BUF_SIZE 500
    char buf[BUF_SIZE], userMsg[BUF_SIZE], errText[BUF_SIZE];

    vsnprintf(userMsg, BUF_SIZE, format, ap); //문자 리스트를 버퍼에 저장, 리스트의 개수와 상관없이 저장함

    if (useErr)//errText문자열 버퍼에 에러메시지 출력
        snprintf(errText, BUF_SIZE, " [%s %s]", (err > 0 && err <= MAX_ENAME) ? ename[err] : "?UNKNOWN?", strerror(err));
    else
        snprintf(errText, BUF_SIZE, ":");
	
	//buf에 errText와 유저메시지 출력
    snprintf(buf, BUF_SIZE, "ERROR%s %s\n", errText, userMsg);

    if (flushStdout)
        fflush(stdout);       /* stdout 버퍼에 남아있는 내용을 모두 출력 */
    fputs(buf, stderr);
    fflush(stderr);           /* stderr가 행별로 버퍼링 되지 않을 경우에 대비? */
}

void errMsg(const char *format, ...)
{
    va_list argList;
    int savedErrno;

    savedErrno = errno;       /* 함수 안에서 내용이 바뀔 것에 대비 */

    va_start(argList, format);//인수의 목록을 초기화하는데 사용
    outputError(TRUE, errno, TRUE, format, argList);// 에러 출력하라고 보냄
    va_end(argList); //모든 인수를 받아들이고 나서 정리 동작을 수행하는데 사용되는 매크로

    errno = savedErrno;
}

void errExit(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errno, TRUE, format, argList); // 에러 출력하라고 보냄
    va_end(argList);

    terminate(TRUE); // 프로그램 종료직전 작업후 프로그램 종료
}

void
err_exit(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errno, FALSE, format, argList);
    va_end(argList);

    terminate(FALSE); // 버퍼를 비우는 등의 작업을 수행하지 않고 프로그램 종료
}

void errExitEN(int errnum, const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(TRUE, errnum, TRUE, format, argList); // 에러종류를 지정하여 오류출력
    va_end(argList);

    terminate(TRUE);
}

void fatal(const char *format, ...)
{
    va_list argList;

    va_start(argList, format);
    outputError(FALSE, 0, TRUE, format, argList); // 무슨 에러인지 모른다고 출력
    va_end(argList);

    terminate(TRUE);
}

void usageErr(const char *format, ...)
{
    va_list argList;

    fflush(stdout);           /* stdout버퍼에 남아있는 내용을 모두 출력한다. */

    fprintf(stderr, "Usage: ");
    va_start(argList, format);
    vfprintf(stderr, format, argList); //리스트내용을 출력하는 함수
    va_end(argList);

    fflush(stderr);           /* stderr가 행별로 버퍼링되지 않을 경우에 대비 */
    exit(EXIT_FAILURE);		//비정상 종료
}

void cmdLineErr(const char *format, ...)
{
    va_list argList;

    fflush(stdout);           /* Flush any pending stdout */

    fprintf(stderr, "Command-line usage error: "); // usageErr와 출력글씨만 다름
    va_start(argList, format);
    vfprintf(stderr, format, argList);
    va_end(argList);

    fflush(stderr);           /* In case stderr is not line-buffered */
    exit(EXIT_FAILURE);
}
