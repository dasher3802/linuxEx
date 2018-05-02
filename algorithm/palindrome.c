#include <stdio.h>
#include <string.h>
#define SIZE 51

int input(char *str);
void felin_check(char *str, int size);

int main(void)
{
	char str[SIZE];
	int len;
	int i;

	len = input(str);
	
	felin_check(str, len);

	return 0;
}

int input(char *str){
	int len = 0;
	int i, sw;	

	do{
		sw = 0;

		scanf("%s", str);

		len = strlen(str);

		for(i = 0; i < len; i++)
			if(str[i] < 'a' || str[i] > 'z')
				sw = 1;

		if(sw > 0)
			printf("소문자가 아니네\n");
	}while(sw);

	return len;
}

void felin_check(char *str, int size)
{
	int i, j;
	
	i = 0;
	j = size - 1;

	while(*(str+i) == *(str+j) && i++ < j--);

	if(i >= j)
		printf("펠린드롬임\n");
	else
		printf("펠린드롬 아님\n");
}
