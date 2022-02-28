#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void check(int** tri, int size)
{
	int** map;
	int result;

	map = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
	{
		map[i] = (int*)malloc(sizeof(int) * size);
	}

	map[0][0] = tri[0][0];
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
			{
				map[i][j] = tri[i][j] + map[i - 1][j];
			}
			else if (j == i)
			{
				map[i][j] = tri[i][j] + map[i - 1][j - 1];
			}
			else
			{
				map[i][j] = max(map[i - 1][j - 1], map[i - 1][j]) + tri[i][j];
			}
		}
	}
	result = 0;
	for (int i = 0; i < size; i++)
	{
		if (result < map[size - 1][i])
		{
			result = map[size - 1][i];
		}
	}
	printf("%d\n", result);
}

int main(void)
{
	int n;
	int** tri;
	scanf("%d", &n);
	tri = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		tri[i] = (int*)malloc(sizeof(int) * n);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tri[i][j] = -1;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			scanf("%d", &tri[i][j]);
		}
	}

	check(tri, n);
}