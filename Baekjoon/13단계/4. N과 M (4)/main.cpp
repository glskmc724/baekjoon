#include <stdio.h>

#define MAX_NUM 8 + 1

void check(int* map, int* visit, int num, int idx, int max, int length)
{
	if (idx == length)
	{
		for (int i = 0; i < length; i++)
		{
			printf("%d ", visit[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for (int i = num; i <= max; i++)
		{
			if (map[i] == 0)
			{
				//map[i] = 1;
				visit[idx] = i;
				check(map, visit, i, idx + 1, max, length);
				//map[i] = 0;
			}
		}
	}
}

int main(void)
{
	int N, M;
	int map[MAX_NUM] = { 0 };
	int visit[MAX_NUM] = { 0 };

	scanf("%d %d", &N, &M);

	check(map, visit, 1, 0, N, M);
}