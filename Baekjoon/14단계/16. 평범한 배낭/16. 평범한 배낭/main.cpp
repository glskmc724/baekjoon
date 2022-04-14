#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

void print(int** dp, int max_num, int max_weight)
{
	printf("    ");
	for (int i = 0; i <= max_weight; i++)
	{
		printf("%3d ", i);
	}
	printf("\n");
	for (int i = 0; i <= max_num; i++)
	{
		printf("%3d ", i);
		for (int j = 0; j <= max_weight; j++)
		{
			printf("%3d ", dp[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int max_num, num;
	int max_weight, weight;
	int** dp;
	int* weight_arr;
	int* value_arr;
	int result;

	scanf("%d %d", &max_num, &max_weight);

	dp = (int**)malloc(sizeof(int*) * (max_num + 1));
	weight_arr = (int*)malloc(sizeof(int) * (max_num + 1));
	value_arr = (int*)malloc(sizeof(int) * (max_num + 1));

	for (int i = 0; i <= max_num; i++)
	{
		dp[i] = (int*)malloc(sizeof(int) * (max_weight + 1));
	}

	for (int i = 1; i <= max_num; i++)
	{
		scanf("%d %d", &weight_arr[i], &value_arr[i]);
	}

	for (int i = 0; i <= max_num; i++)
	{
		for (int j = 0; j <= max_weight; j++)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= max_num; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (weight_arr[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(value_arr[i] + dp[i - 1][j - weight_arr[i]], dp[i - 1][j]);
			}
			/*
			printf("weight_arr[%d]=%d\n", i, weight_arr[i]);
			printf("dp[%d][%d]=max(%d + %d, %d)\n", i, j, value_arr[i], dp[i - 1][j - weight_arr[i]], dp[i - 1][j]);
			print(dp, max_num, max_weight);
			printf("\n");
			*/
		}
	}
	result = 0;
	for (int i = 1; i <= max_num; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (result < dp[i][j])
			{
				result = dp[i][j];
			}
		}
	}
	printf("%d\n", result);
}