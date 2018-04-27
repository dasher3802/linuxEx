#include <stdio.h>

typedef struct _Test1{
	char c1;
	char c2;
	short s;
	int i;
}Test1;

int main(){
	Test1 test;
	
	printf("c1 = %p\n", &(test.c1));
	printf("c2 = %p\n", &(test.c2));
	printf("s = %p\n", &(test.s));
	printf("i = %p\n", &(test.i));

	return 0;
}
