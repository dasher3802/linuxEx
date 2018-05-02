#include <stdio.h>

int function(int num);

int main(void)
{
	int num1, num2, sum = 0;

	printf("숫자 2번 입력 : ");
	scanf("%d %d", &num1, &num2);
	
	while(num1 <= num2)
		sum += function(num1++);

	printf("%d\n", sum);

	return 0;
}

int function(int num)
{
	if(num & ~(~0 << 1))//비트 오른쪽 한자리만 추출
		return 1;
	else
		return function(num>>1)<<1;//function(num/2)*2
}
