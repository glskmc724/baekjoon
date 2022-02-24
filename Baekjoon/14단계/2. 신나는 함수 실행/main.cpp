#include <stdio.h>
#include <stdlib.h>

#define ARR_LENGTH 100 + 1
#define MIN -50
#define MAX 50

int w(int*** w_map, int a, int b, int c)
{
	if (w_map[a + MAX][b + MAX][c + MAX] != 0)
	{
		return w_map[a + MAX][b + MAX][c + MAX];
	}

	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return w(w_map, 20, 20, 20);
	}
	else if (a < b && b < c)
	{
		w_map[a + MAX][b + MAX][c + MAX] = w(w_map, a, b, c - 1) + w(w_map, a, b - 1, c - 1) - w(w_map, a, b - 1, c);
	}
	else
	{
		w_map[a + MAX][b + MAX][c + MAX] = w(w_map, a - 1, b, c) + w(w_map, a - 1, b - 1, c) + w(w_map, a - 1, b, c - 1) - w(w_map, a - 1, b - 1, c - 1);
	}
	return w_map[a + MAX][b + MAX][c + MAX];
}

int main(void)
{
	int a, b, c;
	int*** w_map;
	int result;

	w_map = (int***)malloc(sizeof(int**) * ARR_LENGTH);
	for (int i = 0; i < ARR_LENGTH; i++)
	{
		w_map[i] = (int**)malloc(sizeof(int*) * ARR_LENGTH);
		for (int j = 0; j < ARR_LENGTH; j++)
		{
			w_map[i][j] = (int*)malloc(sizeof(int) * ARR_LENGTH);
			for (int k = 0; k < ARR_LENGTH; k++)
			{
				w_map[i][j][k] = 0;
			}
		}
	}

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
		{
			break;
		}
		else
		{
			result = w(w_map, a, b, c);
			printf("w(%d, %d, %d) = %d\n", a, b, c, result);
		}
	}
}