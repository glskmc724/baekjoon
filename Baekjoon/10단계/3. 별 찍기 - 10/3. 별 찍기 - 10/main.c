#include <stdio.h>
#include <stdlib.h>

void star(int** arr, int n, int step, int pos_x, int pos_y)
{
	if (n == 3)
	{
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				if (x != 1 || y != 1)
				{
					arr[y + pos_y][x + pos_x] = 1;
				}
			}
		}
		return;
	}

	for (int y = pos_y; y < n + pos_y; y += step)
	{
		for (int x = pos_x; x < n + pos_x; x += step)
		{
			if (x != pos_x + step || y != pos_y + step) 
			{
				star(arr, n / 3, step / 3, x, y);
			}
		}
	}
}

int main(void)
{
	int n;
	int** arr;
	scanf("%d", &n);
	arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			arr[y][x] = 0;
		}
	}

	star(arr, n, n / 3, 0, 0);
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] == 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}