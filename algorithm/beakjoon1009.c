#include <stdio.h>

int main(void)
{
	int count, a, b, tot;

	int arr[10][4]={
		{0},
		{1},
		{2,4,8,6},
		{3,9,7,1},
		{4,6},
		{5},
		{6},
		{7,9,3,1},
		{8,4,2,6},
		{9, 1}
	};

	scanf("%d", &count);
	
	while(0 < count--)
	{
		scanf("%d %d", &a, &b);
		a %= 10;
		b--;

		switch(a){
			case 2:
			case 3:
			case 7:
			case 8:
				b %= 4;
				break;
			case 4:
			case 9:
				b %= 2;
				break;
			default:
				b=0;
		}

		printf("%d", arr[a][b]);
	}
}