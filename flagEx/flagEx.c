#include <stdio.h>

struct Flags1{//int 8byte
unsigned int a : 1;
unsigned int b : 3;
unsigned int c : 31;
};

struct Flags2{//int 4byte
unsigned int a : 1;
unsigned int b : 3;
unsigned int c : 7;
};

int main()
{
	struct Flags1 f1;
	struct Flags2 f2;

	printf("sizeof(f1) = %d\n", sizeof(f1));
	printf("sizeof(f2) = %d\n", sizeof(f2));

	return 0;
}
