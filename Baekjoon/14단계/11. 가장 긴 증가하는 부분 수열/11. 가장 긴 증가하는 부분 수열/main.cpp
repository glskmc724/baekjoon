#include <stdio.h>
#include <stdlib.h>

#define max(a, b) a > b ? a : b

int main(void)
{
	int len;
	int* arr;
	int* dp;
	int idx, last_value;
	int result;

	scanf("%d", &len);
	arr = (int*)malloc(sizeof(int) * (len + 1));
	dp = (int*)malloc(sizeof(int) * (len + 1));

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &arr[i + 1]);
	}

	for (int i = 0; i <= len; i++)
	{
		dp[i] = 0;
	}

	arr[0] = dp[0] = 0;
	idx = 0;
	for (int i = 1; i <= len; i++)
	{
		last_value = 0;
		for (int j = 0; j <= i; j++)
		{
			if (arr[i] > arr[j])
			{
				last_value = max(last_value, dp[j]);
			}
		}
		dp[i] = last_value + 1;
		/*
		printf("idx: %d\n", idx);
		printf("dp: %d\n", dp[i]);

		printf("i: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", i);
		}
		printf("\nA: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", arr[i]);
		}
		printf("\nD: ");
		for (int i = 0; i <= len; i++)
		{
			printf("%3d ", dp[i]);
		}
		printf("\n\n");
		*/
	}

	result = 0;
	for (int i = 1; i <= len; i++)
	{
		if (result < dp[i])
		{
			result = dp[i];
		}
		//printf("%d\n", dp[i]);
	}
	printf("%d\n", result);
}