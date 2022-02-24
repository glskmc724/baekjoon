#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NUM_COLORS 3

typedef struct
{
	char color; // 1: Red, 2: Green, 3: Blue
	int cost;
} house;

int min(int a, int b)
{
	if (a > b)
	{
		return b;
	}
	else
	{
		return a;
	}
}

void check(int** map, int num_houses)
{
	int sum;
	int** cost;
	int result;
	
	cost = (int**)malloc(sizeof(int*) * num_houses);
	for (int i = 0; i < num_houses; i++)
	{
		cost[i] = (int*)malloc(sizeof(int*) * NUM_COLORS);
	}

	cost[0][0] = map[0][0];
	cost[0][1] = map[0][1];
	cost[0][2] = map[0][2];

	for (int i = 1; i < num_houses; i++)
	{
		cost[i][0] = map[i][0] + min(cost[i - 1][1], cost[i - 1][2]);
		cost[i][1] = map[i][1] + min(cost[i - 1][0], cost[i - 1][2]);
		cost[i][2] = map[i][2] + min(cost[i - 1][0], cost[i - 1][1]);
	}

	result = INT_MAX;
	for (int j = 0; j < NUM_COLORS; j++)
	{
		if (result > cost[num_houses - 1][j])
		{
			result = cost[num_houses - 1][j];
		}
	}
	printf("%d\n", result);
}

int main(void)
{
	int N;
	int** map;
	scanf("%d", &N);
	map = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * NUM_COLORS);
		for (int j = 0; j < NUM_COLORS; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	check(map, N);
}