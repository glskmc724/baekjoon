#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_COLORS 3

int min = INT_MAX;

typedef struct
{
	char color; // 1: Red, 2: Green, 3: Blue
	int cost;
} house;

void check(int** map, house* arr, int house_idx, int arr_idx, int house_max)
{
	int sum;

	if (house_idx == house_max)
	{
		sum = 0;

		for (int i = 0; i < arr_idx; i++)
		{
			sum += arr[i].cost;
			//printf("(color: %d cost: %d), ", arr[i].color, arr[i].cost);
		}
		//printf("\n");

		if (min > sum)
		{
			min = sum;
		}

		return;
	}

	for (int i = 0; i < NUM_COLORS; i++)
	{
		if (arr_idx > 0)
		{
			if (arr[arr_idx - 1].color == (i + 1))
			{
				continue;
			}
		}

		arr[arr_idx].cost = map[house_idx][i];
		arr[arr_idx].color = i + 1;
		check(map, arr, house_idx + 1, arr_idx + 1, house_max);
		arr[arr_idx].cost = 0;
		arr[arr_idx].color = 0;
	}
}

int main(void)
{
	int N;
	int** color;
	house* arr;
	scanf("%d", &N);
	color = (int**)malloc(sizeof(int*) * N);
	arr = (house*)malloc(sizeof(house) * N);
	for (int i = 0; i < N; i++)
	{
		color[i] = (int*)malloc(sizeof(int) * NUM_COLORS);
		for (int j = 0; j < NUM_COLORS; j++)
		{
			scanf("%d", &color[i][j]);
		}
	}
	check(color, arr, 0, 0, N);
	printf("%d\n", min);
}