#include <stdio.h>
#include <stdlib.h>

#define LENGTH 9
#define BLOCK_LENGTH 3

int flag = 0;

int sudoku(int** map, int x, int y, int value)
{
	int idx;

	for (int i = 0; i < LENGTH; i++)
	{
		if (map[i][x] == value)
		{
			return 0;
		}
	}

	for (int i = 0; i < LENGTH; i++)
	{
		if (map[y][i] == value)
		{
			return 0;
		}
	}
	
	for (int i = 0; i < BLOCK_LENGTH; i++)
	{
		for (int j = 0; j < BLOCK_LENGTH; j++)
		{
			if (value == map[(y / 3) * 3 + i][(x / 3) * 3 + j])
			{
				return 0;
			}
		}
	}

	return 1;
}

void check(int** map, int x, int y, int count, int max)
{
	if (count == max)
	{
		flag = 1;
		for (int i = 0; i < LENGTH; i++)
		{
			for (int j = 0; j < LENGTH; j++)
			{
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

	if (map[y][x] == 0)
	{
		for (int i = 0; i < LENGTH; i++)
		{
			if (sudoku(map, x, y, i + 1) == 1)
			{
				map[y][x] = i + 1;
				check(map, x, y, count + 1, max);
			}

		}
		if (flag == 1)
		{
			return;
		}
		map[y][x] = 0;
	}
	else
	{
		if (x == LENGTH - 1)
		{
			check(map, 0, y + 1, count, max);
		}
		else
		{
			check(map, x + 1, y, count, max);
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
	
	check(map, 0, 0, 0, count);
}