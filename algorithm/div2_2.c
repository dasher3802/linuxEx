#include <stdio.h>
#include <time.h>

long function(long num);

int main(void)
{
	long num1, num2, tot;
	float gap;

//	time_t startTime = 0, endTime = 0;

//	printf("두 수 입력 : ");
	scanf("%ld %ld",&num1, &num2);
	
//	startTime = clock();
	tot = function(num2) - function(num1 - 1);

	printf("%ld", tot);
//	endTime = clock();

//	gap = (float)(endTime-startTime)/(CLOCKS_PER_SEC);

//	printf("측정 시간 :%f 초\n", gap);
	return 0;
}

long function(long num)
{
	long tot = 0;
	long b = 2;
	long hol = (num + 1)/2;


	while(b <= num)
	{
		tot += (num+b) / (b*2) * b;
		b *= 2;
	}

	return tot + hol;
}
