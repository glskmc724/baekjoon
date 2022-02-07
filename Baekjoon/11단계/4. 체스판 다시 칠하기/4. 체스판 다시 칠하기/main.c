#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int color;
	int check;
} block;

int main(void)
{
	int N, M;
	char* blocks;
	block** arr;
	int count = 0;
	int black_count = 0;
	int white_count = 0;
	int compare_block_w[8][8] = {
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 }
	};
	int compare_block_b[8][8] = {
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 },
		{ 0,1,0,1,0,1,0,1 },
		{ 1,0,1,0,1,0,1,0 }
	};
	int min = 1234567;
	scanf("%d %d", &N, &M);
	arr = (block**)malloc(sizeof(block*) * (N + 15));
	for (int i = 0; i < N + 15; i++)
	{
		arr[i] = (block*)malloc(sizeof(block) * (M + 15));
	}
	blocks = (char*)malloc(sizeof(char) * M);
	
	for (int i = 1; i < N + 1; i++)
	{
		scanf("%s", blocks);
		for (int j = 0; j < M; j++)
		{
			if (blocks[j] == 'W')
			{
				arr[i][j + 1].color = 1;
			}
			else if (blocks[j] == 'B')
			{
				arr[i][j + 1].color = 0;
			}
		}
	}

	for (int i = 0; i < N + 15; i++)
	{
		for (int j = 0; j < M + 15; j++)
		{
			if (!(arr[i][j].color == 1 || arr[i][j].color == 0))
			{
				arr[i][j].color = -1;
			}
		}

	}

	for (int i = 1; i < N - 7 + 1; i++)
	{
		for (int j = 1; j < M - 7 + 1; j++)
		{
			for (int y = i; y < i + 8; y++)
			{
				for (int x = j; x < j + 8; x++)
				{
					if (arr[y][x].color != compare_block_w[y - i][x - j])
					{
						white_count += 1;
					}

					if (arr[y][x].color != compare_block_b[y - i][x - j])
					{
						black_count += 1;
					}

					if (black_count > white_count)
					{
						count = white_count;
					}
					else
					{
						count = black_count;
					}
				}
			}
			if (min > count)
			{
				min = count;
			}
			//printf("count: %d, min: %d\n", count, min);
			black_count = white_count = count = 0 ;
		}
	}
	printf("%d\n", min);
	/*
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < M + 2; j++)
		{
			printf("%2d ", arr[i][j].color);
		}
		printf("\n");
	}
	*/
}