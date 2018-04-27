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
	int low_row, high_row;
	int low_col, high_col;
	int x, y;
	int data = 1;
	
	low_col = low_row = 0;
	high_row = high_col = size;
	x = y = 0;

	while(low_row < high_row || low_col < high_col)
	{
		for(x = low_row; x < high_row; x++)
			(*arr)[y][x] = data++;
		low_col++;
		x--;

		for(y = low_col; y < high_col; y++)
			(*arr)[y][x] = data++;
		high_row--;
		y--;

		for(x = high_row-1; x >= low_row; x--)
			(*arr)[y][x] = data++;
		high_col--;
		x++;

		for(y = high_col-1; y >= low_col; y--)
			(*arr)[y][x] = data++;
		low_row++;
		y++;
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
