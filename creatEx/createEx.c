#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
	int fd, pos;
	int len;
	char wbuf[SIZE], rbuf[SIZE];
	int wcount, rcount;

	fd = open("./test.txt", O_RDWR | O_CREAT | O_TRUNC, \
			S_IRWXU | \
			S_IRGRP | S_IWGRP | S_IROTH);
	
	//open(pathname, flag, mode)
	//flag
	//O_RDONLY 	읽기 열기
	//O_WRONLY 	쓰기 열기
	//O_RDWR	읽기, 쓰기 열기
	//O_CREAT	파일이 이미 존재하지 않으면 새로 만든다.
	//O_TRUNC	파일의 길이를 0으로
	//O_APPEND	파일끝에 추가해서 작성
	//mode
	//S_IRUSR	사용자-읽기
	//S_IWUSR	사용자-쓰기
	//S_IXUSR	사용자-실행
	//S_IRGRP	그룹-읽기
	//S_IWGRP	그룹-쓰기
	//S_IXGRP	그룹-실행
	//S_IROTH	기타-읽기
	//S_IWOTH	기타-쓰기
	//S_IXOTH	기타-실행
	
	if(fd == -1)
	{
		printf("file open error!!\n");
		return -1;
	}
		
	strcpy(wbuf, "Do not count the before they hatch.");
	len = strlen(wbuf);
	wcount = write(fd, wbuf, len);
	//파일 쓰기, 글자수 반환

	pos = lseek(fd, 0, SEEK_SET);
	//파일 커서 위치 변경, 변경후 위치 반환
	//lseek(fd, offset, SEEK_SET);//처음기준 offset이동
	//lseek(fd, offset, SEEK_CUR);//현재 커서 기준 offset이동
	//lseek(fd, offset, SEEK_END);//끝 기준 offset이동
		
	rcount = read(fd, rbuf, len);//파일 읽기

	printf("wcount = %d\n", wcount);
	printf("pos = %d\n", pos);
	printf("rcount = %d\n", rcount);
	printf("rbuf = %s\n", rbuf);

	close(fd);
/*
	fd = creat("./test2.txt", 0764);
	if(fd == -1)
	{
		printf("file creat error!!\n");
		return -1;
	}
	printf("%d", fd);
*/
	return 0;
}
