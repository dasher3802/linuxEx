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

	inputFd = open(argv[1], O_RDONLY);
	if(-1 == inputFd)
		printf("file open error!");

	
	outputFd = open(argv[2], \
		O_WRONLY | O_TRUNC | O_CREAT, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(-1 == outputFd)
		printf("file open error!");

	while(0 < (len = read(inputFd, buf, SIZE)))
		write(outputFd, buf, len);

	close(inputFd);
	close(outputFd);
	
	return 0;
}
