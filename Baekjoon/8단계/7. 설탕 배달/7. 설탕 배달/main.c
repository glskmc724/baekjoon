#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int weight;
	int** arr;
	int height;

	scanf("%d", &weight);

	arr = (int**)malloc(sizeof(int*) * (weight + 1));
	for (int i = 0; i < (weight + 1); i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * (weight + 1));
	}

	for (int i = 0; i < (weight + 1); i++)
	{
		for (int j = 0; j < (weight + 1); j++)
		{
			arr[i][j] = 0;
		}
	}

	arr[0][0] = 3;
	height = 0;
	for (int x = 0; x < weight; x++)
	{
		for (int y = 0; y < height + 1; y++)
		{
			if (y + 1 != weight)
			{
				if (arr[y][x + 1] == 0)
				{
					arr[y][x + 1] = arr[y][x] + 3;
					arr[y + 1][x + 1] = arr[y][x] + 5;
				}
				else
				{
					for (int k = 0; k < weight; k++)
					{
						if (arr[k][x + 1] == 0)
						{
							height = k;
							break;
						}
					}
					arr[height][x + 1] = arr[y][x] + 3;
					arr[height + 1][x + 1] = arr[y][x] + 5;
				}
			}
		}
		height += 1;
	}

	for (int i = 0; i < weight; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}