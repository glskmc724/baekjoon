#include <stdio.h>
#include <stdlib.h>

#define LENGTH 9
#define BLOCK_LENGTH 3

int flag = 0;

int* sudoku(int** map, int x, int y)
{
	int idx;
	int* arr;

	arr = (int*)malloc(sizeof(int) * LENGTH);

	for (int i = 0; i < LENGTH; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < LENGTH; i++)
	{
		idx = map[i][x];
		if (idx != 0)
		{
			arr[idx - 1] += 1;
		}
	}

	for (int i = 0; i < LENGTH; i++)
	{
		idx = map[y][i];
		if (idx != 0)
		{
			arr[idx - 1] += 1;
		}
	}
	
	for (int i = 0; i < BLOCK_LENGTH; i++)
	{
		for (int j = 0; j < BLOCK_LENGTH; j++)
		{
			idx = map[(y / 3) * 3 + i][(x / 3) * 3 + j];
			if (idx != 0)
			{
				arr[idx - 1] += 1;
			}
		}
	}

	return arr;
}

void check(int** map, int count, int max)
{
	int* result;
	
	if (count >= max)
	{
		printf("\n");
		for (int i = 0; i < LENGTH; i++)
		{
			for (int j = 0; j < LENGTH; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		flag = 1;
		return;
	}

	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			if (map[i][j] == 0)
			{
				result = sudoku(map, j, i);
				for (int k = 0; k < LENGTH; k++)
				{
					if (result[k] == 0)
					{
						map[i][j] = k + 1;
						check(map, count + 1, max);
						map[i][j] = 0;
					}
				}
				if (flag == 1)
				{
					return;
				}
				free(result);
			}
		}
	}
}

int main(void)
{
	int** map;
	int count;
	map = (int**)malloc(sizeof(int*) * LENGTH);
	for (int i = 0; i < LENGTH; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * LENGTH);
	}

	count = 0;
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
			{
				count += 1;
			}
		}
	}
	
	check(map, 0, count);
}