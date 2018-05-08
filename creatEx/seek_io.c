/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2017.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 4-3 */

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int main(int argc, char *argv[])
{
    size_t len;
    off_t offset;
    int fd, ap, j;
    char *buf;
    ssize_t numRead, numWritten;

    //실행시 받는 인자가 3개 미만이거나 help를 요철한경우
    if (argc < 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n",
                 argv[0]);

    //파일을 읽기쓰기 용으로 없는경우 생성해서 열기
    fd = open(argv[1], O_RDWR | O_CREAT |
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH);                     /* rw-rw-rw- */
    //열기에 실패한 경우
    if (fd == -1)
        errExit("open");

    //실행 매개변수 2번째 부터 마지막 매개변수까지 r(R)이 있는치 찾음  
    for (ap = 2; ap < argc; ap++) {
        switch (argv[ap][0]) {
        case 'r':   /* Display bytes at current offset, as text */
        case 'R':   /* Display bytes at current offset, in hex */
	    //arg가 가리키는 문자열의 길이를 반환
            len = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
	    
	    //버퍼에 반환된 문자열의 길이만큼 공간을 할당
            buf = malloc(len);
	    //할당 안되면 에러
            if (buf == NULL)
                errExit("malloc");

	    //할당된만큼 파일에서 읽어옴
            numRead = read(fd, buf, len);
	    //못읽어온경우 에러
            if (numRead == -1)
                errExit("read");

	    //읽은 글자수가 0이면 다읽은것으로 간주하고 파일의 끝임을 출력
            if (numRead == 0) {
                printf("%s: end-of-file\n", argv[ap]);
            } else {//읽은 데이터가 있는 경우
                printf("%s: ", argv[ap]);
                for (j = 0; j < numRead; j++) {
                    if (argv[ap][0] == 'r')
                        printf("%c", isprint((unsigned char) buf[j]) ?
                                                buf[j] : '?');
                    else
                        printf("%02x ", (unsigned int) buf[j]);
                }
                printf("\n");
            }

            free(buf);
            break;

        case 'w':   /* Write string at current offset */
            numWritten = write(fd, &argv[ap][1], strlen(&argv[ap][1]));
            if (numWritten == -1)
                errExit("write");
            printf("%s: wrote %ld bytes\n", argv[ap], (long) numWritten);
            break;

        case 's':   /* Change file offset */
            offset = getLong(&argv[ap][1], GN_ANY_BASE, argv[ap]);
            if (lseek(fd, offset, SEEK_SET) == -1)
                errExit("lseek");
            printf("%s: seek succeeded\n", argv[ap]);
            break;

        default:
            cmdLineErr("Argument must start with [rRws]: %s\n", argv[ap]);
        }
    }

    if (close(fd) == -1)
        errExit("close");

    exit(EXIT_SUCCESS);
}
