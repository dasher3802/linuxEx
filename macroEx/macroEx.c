#include <stdio.h>
#define MUL(x, y) ((x) * (y))

int main(){
	int a = 1, b = 2, c = 3, d = 4, k = 0;
	k=MUL(a + b, c + d);

	printf("(a + b) * (c + d)%d\n", k);
	return 0;
}
