#include <stdio.h>
#include <stdlib.h>

void make_arr(int ***arr, int size);
void setNum_arr(int ***arr, int size);
void print_arr(int ***arr, int size);


int main(void)
{
	int **arr;
	int input = 1;
	int i, j, sw;

	while(input)
	{
		printf("크기 입력 : ");
		scanf("%d", &input);
		
		make_arr(&arr, input);
		setNum_arr(&arr, input);
		print_arr(&arr, input);
	}
	return 0;
}

void make_arr(int ***arr, int size)
{
	int i, j;
	
	*arr = (int **)malloc(size*sizeof(int*));
	for(i = 0; i< size; i++){
		(*arr)[i] = (int *)malloc(size*sizeof(int));
		for(j = 0; j < size; j++){
			(*arr)[i][j] = 0;
		}
	}
}

void setNum_arr(int ***arr, int size)
{
	int i, x, y, sw, data;

	x = 0;
	y = 0;
	sw = 1;
	data = 1;

	while(size)
	{	
		for(i = 0; i< size; i++){
			(*arr)[y][x] = data++;
			x += sw;
		}
		
		x -= sw;
		y += sw;
		size --;

		for(i = 0; i < size; i++){
			(*arr)[y][x] = data++;
			y += sw;
		}

		y -= sw;
		sw *= -1;
		x += sw;
	}
}

void print_arr(int ***arr, int size)
{
	int i, j;

	for(i = 0; i< size; i++){
		for(j = 0; j< size; j++){
			printf("[%3d] ", (*arr)[i][j]);
		}
		puts("");
	}	
}
