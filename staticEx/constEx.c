#include <stdio.h>
int max(const int *p);

void main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	int m;
	m = max(a);

	printf("max = %d\n", m);
}

int max(const int *p)
{
	int i, tmp = -10000;

	for(i = 0; i < 10; i++)
	{
		if(tmp < p[i])
			tmp = p[i];
	}
	return tmp;
}
