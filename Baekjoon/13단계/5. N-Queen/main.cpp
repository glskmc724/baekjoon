#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int idx = 0; 
int cnt = 0;

int can_die(int** map, int n, int x, int y)
{
	int num;

	for (int i = 0; i < n; i++)
	{
		if (map[y][i] == 1)
		{
			return 1;
		}
	}

	for (int i = 0; i < n; i++) 
	{
		if (map[i][x] == 1)
		{
			return 1;
		}
	}

	num = x > y ? y : x;
	for (int i = y - num, j = x - num; i < n && j < n; i++, j++)
	{
		if (map[i][j] == 1)
		{
			return 1;
		}
	}

	num = n - x - 1 > y ? y : n - x - 1;
	for (int i = y - num, j = x + num; i < n && j >= 0; i++, j--)
	{
		if (map[i][j] == 1)
		{
			return 1;
		}
	}

	return 0;
}

void print(int** map, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			if (map[i][j] == 1)
			{
				printf("%3d ", 1);
			}
			else
			{
				if (can_die(map, size, j, i) == 1)
				{
					printf("%3d ", 2);
				}
				else
				{
					printf("%3d ", 0);
				}
			}
		}
		printf("\n");
	}
	printf("\n");
}

void check(int** map, int x, int y, int count, int size)
{
	int i, j;

	//printf("%d\n", count);
	//print(map, size);

	if (count == size)
	{
		cnt += 1;
		return;
	}

	for (j = x; j < size; j++)
	{
		if (can_die(map, size, j, count) == 0)
		{
			map[count][j] = 1;
			check(map, 0, count + 1, count + 1, size);
			map[count][j] = 0;
		}
	}
} 

int main(void)
{
	int** map;
	int idx;
	int size;
	int count;
	int sum = 0;
	clock_t start, end;
	double result;

	while (1)
	{
		scanf("%d", &size);

		if (size == 0)
		{
			break;
		}

		idx = 0;

		map = (int**)malloc(sizeof(int*) * size);
		for (int i = 0; i < size; i++)
		{
			map[i] = (int*)malloc(sizeof(int) * size);
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				map[i][j] = 0;
			}
		}

		start = clock();
		check(map, 0, 0, 0, size);
		end = clock();

		result = (double)(end - start) / 1000;

		//map[1][0] = 1;
		//check(map, 0, 0, 1, size);
		printf("%d\n", cnt);
		printf("경과시간: %.2lfsec\n", result);
	}
}