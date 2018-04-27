#include <stdio.h>

void increaseNumber()
{
	static int num1 = 0;
	printf("%d\n", num1);

	num1++;
}

int main(void)
{
	increaseNumber();
	increaseNumber();
	increaseNumber();
	increaseNumber();

	return 0;	
}
