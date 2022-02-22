#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min = INT_MAX;

int sum(int** map, int* arr, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == j)
			{
				continue;
			}

			if (arr[i] == 1 && arr[j] == 1)
			{
				sum += map[i][j];
			}
		}
	}
	return sum;
}

int* reverse(int* arr, int length)
{
	int* newarr;

	newarr = (int*)malloc(sizeof(int) * length);

	for (int i = 0; i < length; i++)
	{
		if (arr[i] == 1)
		{
			newarr[i] = 0;
		}
		else
		{
			newarr[i] = 1;
		}
	}

	return newarr;
}

void check(int** map, int* arr, int idx, int count, int length)
{
	int* newarr;
	int diff;

	if (count == length / 2)
	{
		newarr = reverse(arr, length);
		diff = abs(sum(map, arr, length) - sum(map, newarr, length));
		//printf("%d\n", sum(map, arr, length));
		//printf("%d\n", sum(map, newarr, length));
		
		if (min > diff)
		{
			min = diff;
		}

		/*
		for (int i = 0; i < length; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		*/

		return;
	}

	for (int i = idx; i < length; i++)
	{
		arr[i] = 1;
		check(map, arr, i + 1, count + 1, length);
		//printf("%d\n", sum(map, arr, length));
		arr[i] = 0;
	}
}

int main(void)
{
	int N;
	int** map;
	int* arr;

	scanf("%d", &N);

	map = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * N);
	}

	arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	check(map, arr, 0, 0, N);
	//printf("min: %d\n", min);
	printf("%d\n", min);
}