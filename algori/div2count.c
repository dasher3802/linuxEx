#include <stdio.h>

int function(int num);

int main(void)
{
	int num;

	printf("숫자 입력 : ");
	scanf("%d", &num);
	printf("%d\n", function(num));

	return 0;
}

int function(int num)
{
	if(num & ~(~0 << 1))
		return 1;
	else
		return 2 * function(num>>1);
}
