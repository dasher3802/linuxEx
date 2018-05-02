#include <stdio.h>
#include <time.h>

long function(long num);

int main(void)
{
	long num1, num2, tot;
	float gap;

//	printf("두 수 입력 : ");
	scanf("%ld %ld",&num1, &num2);
	
	tot = function(num2) - function(num1 - 1);

	printf("%ld", tot);

	return 0;
}

long function(long num)
{
	long tot = 0;
	long b = 2;
	long hol = (num + 1)/2;

	while(b <= num)//2의 개수, 4의 개수, 8의 개수... 더하는 반복문
	{
		tot += (num+b) / (b*2) * b; 
		b *= 2;
	}

	return tot + hol;//짝수합 + 홀수합
}
/*
2  = 2 x 1 = 2
4  = 2 x 1 + 4 x 1 = 6
6  = 2 x 2 + 4 x 1 = 8
8  = 2 x 2 + 4 x 1 + 8 x 1 = 16
10 = 2 x 3 + 4 x 1 + 8 x 1 = 18
12 = 2 x 3 + 4 x 2 + 8 x 1 = 22
14 = 2 x 4 + 4 x 2 + 8 x 1 = 24
16 = 2 x 4 + 4 x 2 + 8 x 1 + 16 x 1 = 40 
18 = 2 x 5 + 4 x 2 + 8 x 1 + 16 x 1 = 42
20 = 2 x 5 + 4 x 3 + 8 x 1 + 16 x 1 = 46
22 = 2 x 6 + 4 x 3 + 8 x 1 + 16 x 1 = 48
24 = 2 x 6 + 4 x 3 + 8 x 2 + 16 x 1 = 56
26 = 2 x 7 + 4 x 3 + 8 x 2 + 16 x 1 = 58

주어진 수가 n 일경우
2의 개수 = (n+2)/4
4의 개수 = (n+4)/8
8의 개수 = (n+8)/16
16의 개수 = (n+16)/32
*/
