#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 1024

int main(int argc, char *argv[])
{
	char buf[SIZE];
	int inputFd, outputFd;
	int len;

	if(argc < 3){
		write(2, "Usage : copy file1 file2\n", 25);//2는 에러에 작성
		//perror("Usage : copy file1 file2\n");//에러 번호용 출력함수
		return -1;
	}

	inputFd = open(argv[1], O_RDONLY);
	outputFd = open(argv[2], \
		O_WRONLY | O_TRUNC | O_CREAT, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	
	if( outputFd < 0 || inputFd < 0)
		printf("file open error!");

	while((len = read(inputFd, buf, sizeof(buf))) > 0)
		write(outputFd, buf, len);

	close(inputFd); 
	close(outputFd);
	
	return 0;
}
